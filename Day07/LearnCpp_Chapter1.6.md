# 1.6 - Uninitialized Variables and Undefined Behavior

## 1. Temel Kavramlar
Bazı programlama dillerinin aksine C/C++ dillerinde değişkenler otomatik olarak belirli bir değerle başlatılmaz. İşletim sistemi bu değişken için bellekte (RAM) bir yer ayırdığında, o bellek adresinde daha önceki işlemlerden arta kalan "çöp" (garbage) veriler bulunabilir.

*   **Initialized (Başlatılmış):** Nesneye, tanımlandığı anda bilinen bir değer atanmıştır (Örn: `int x {5};`).
*   **Uninitialized (Başlatılmamış):** Nesneye henüz bilinen bir değer atanmamıştır. İçinde çöp veri barındırır.
    *   *Ek Not:* `int x;` dediğimizde biz buna **default-initialization (varsayılan başlatma)** diyoruz, ancak bir değerle başlatılmadığı için pratikte buna da *uninitialized* denir.
*   **Assignment (Atama):** Nesneye, tanımlandığı andan *sonra* bilinen bir değer atanmasıdır (Örn: `x = 5;`).

## 2. Neden Otomatik Sıfırlanmaz? (C'nin Mirası)
Bu başlatma eksikliği C dilinden gelen bir mirastır ve doğrudan **performans optimizasyonu** ile ilgilidir. Milyonlarca değişkenin olduğu büyük bir sistemde, her tanımlanan değişkenin içine işletim sistemi tarafından `0` yazılması işlemci (CPU) için ciddi bir zaman ve performans kaybıdır. 

*   **Pratik Tavsiye:** Şimdilik bizim tüm değişkenleri başlatmamız (initialize etmemiz) gerek; çünkü henüz çok devasa verilerle uğraşmadığımız için güvenliğin faydası performanstan daha önemli. İleride dile tam hakim olduğumuzda, optimizasyon gereken yerlerde bilinçli olarak verileri başlatmadan bırakabiliriz.

## 3. Undefined Behavior (UB - Tanımsız Davranış)
Başlatılmamış bir değişkenin değerini okumak ve kullanmak, Undefined Behavior (Tanımsız Davranış) durumuna yol açar. UB, davranışın C++ standardı tarafından net bir şekilde belirlenmediği kodun yürütülmesidir. Belirli bir kuralı yoktur ve sonuçları öngörülemez.

**UB Durumunda Karşılaşılabilecek Olası Sonuçlar:**
*   Program her çalıştığında farklı, rastgele bir sonuç verebilir.
*   Program sürekli aynı hatalı sonucu verebilir.
*   Program tutarsız davranabilir (bazen doğru, bazen yanlış).
*   Program çalışıyor gibi görünür ama ilerleyen kısımlarda yanlış sonuç verir.
*   Program ya anında ya da daha sonra çökebilir.
*   Program bir derleyicide çalışırken, diğerinde hata verebilir.
*   Program, alakasız gibi görünen başka bir kod parçasını değiştirene kadar çalışır.

**Altın Kural:** C++'ta UB'ye neden olacak her durumdan ne pahasına olursa olsun kaçınılmalıdır.

## 4. Derleyici Uyarıları ve "doNothing" Hilesi
Modern derleyiciler `int x;` tanımlayıp bunu doğrudan yazdırmaya çalıştığımızda "uninitialized variable" uyarısı verir. Bu hatayı susturup bellekteki "çöp" değeri görmek için şöyle bir hile kullanılabilir:

    void doNothing(int&) {
        // Derleyiciyi kandırmak için yazılmış boş fonksiyon
    }

    int main() {
        int x; // Başlatılmamış değişken
        doNothing(x); // Derleyici, değişkenin burada kullanıldığını sanır
        std::cout << x << '\n';
        return 0;
    }

**Visual Studio Debug vs Release Farkı:**
Yukarıdaki kodu Visual Studio'da **Debug (Hata Ayıklama)** yapılandırmasında çalıştırırsak sonuç `-858993460` çıkar. Bu, MSVC derleyicisinin hata ayıklama sırasında belleği başlatırken kullandığı varsayılan değerdir (hatayı fark etmemiz içindir). Gerçek rastgele çöp veriyi görmek için kodun **Release (Yayın)** modunda denenmesi gerekir.

## 5. Diğer Belirsizlik Türleri

### Implementation-defined Behavior (Uygulama Tanımlı Davranış)
C++ standardı bazı kuralların kararını derleyiciye (uygulamaya) bırakır, ancak derleyicinin **seçtiği kuralı belgelemesini ve hep aynı şekilde davranmasını** şart koşar.
*   *Örnek:* `std::cout << sizeof(int);`. Bazı derleyiciler buna 4 der (MSVC gibi), bazıları 2 der. Kendi içlerinde tutarlıdırlar.

### Unspecified Behavior (Belirtilmemiş Davranış)
Standardın derleyiciye esneklik sağladığı, ancak derleyicinin kararını **belgelemesinin zorunlu olmadığı** durumlardır.

**Önemli Tavsiye:** Mümkün olduğunca uygulamaya tanımlı ve belirtilmemiş davranışlardan da kaçınmalıyız. Çünkü bunlar, kodumuzun farklı bir derleyiciyle derlendiğinde (hatta proje ayarlarını değiştirirsek aynı derleyiciyle bile) bozulmasına neden olabilir.

---

## 6. Active Recall (Soru & Cevap)

**Soru 1: C++ neden diğer modern diller gibi değişkenleri tanımlandıkları anda otomatik olarak `0` ile başlatarak bizi bu tehlikeli "UB" durumundan kurtarmıyor?**
**Cevap:** Bu tamamen performans optimizasyonuyla ilgilidir. Otomatik sıfırlama, bellek kapasitesini şişirmez ancak işlemcinin o bellek adreslerine tek tek `0` yazması için zaman harcamasına neden olur. Çok fazla verinin olduğu sistemlerde bu ciddi bir yavaşlamaya yol açar. C++, performansı maksimumda tutmak için güvenliği programcının sorumluluğuna bırakır.

**Soru 2: Visual Studio'da debug modunda çalıştırdığında `int x;` için rastgele bir çöp veri yerine sürekli `-858993460` gördün. Derleyici sence neden debug modunda kasıtlı olarak hep bu sabit sayıyı veriyor olabilir?**
**Cevap:** Bu Visual Studio'nun (MSVC) belleği başlatırken kullandığı varsayılan değerdir. Eğer gerçekten rastgele (normal görünen) bir sayı verseydi, kodun mantık hatası içerdiğini fark etmek zor olurdu. Bu sabit ve absürt sayıyı görünce hatanın "başlatılmamış değişken" olduğunu hemen anlarız.

**Soru 3: Kodunda yanlışlıkla başlatılmamış bir değişkeni kullandın. Programı çalıştırdın ve hiçbir hata vermeden tam da istediğin doğru sonucu ekrana yazdırdı. "Kodumda sorun yokmuş, UB beni kötü etkilemedi" diyebilir misin?**
**Cevap:** Hayır diyemeyiz. Bu sadece bir şanstır; o an rastgele istenilen değer gelmiştir ve yarın aynısı gelmeyebilir. Ayrıca bazı derleyiciler kuralları esnetip kendi doğrusunu uygulayabilir. Başka cihaza geçildiğinde veya koda ekleme yapıldığında bu şans biter ve program çöker.