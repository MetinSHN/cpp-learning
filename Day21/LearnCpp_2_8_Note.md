# LearnCpp 2.8 — Programs with Multiple Code Files (Çoklu Dosya Mimarisi)

## 1. Neden Projeleri Çoklu Dosyalara Böleriz?
Bütün bir projeyi tek bir `main.cpp` içine yazmak yerine modüllere ayırmanın üç temel mühendislik sebebi vardır:
*   **Organizasyon ve Yönetilebilirlik:** Kod tabanı büyüdükçe (örneğin binlerce satır), mantıksal parçaları (örn. matematik işlemleri, kullanıcı arayüzü) kendi dosyalarına ayırmak kodu okunabilir kılar.
*   **Yeniden Kullanılabilirlik (Reusability):** Bir dosyaya yazdığınız bağımsız bir fonksiyonu (örn. `add.cpp`), başka bir projeye sadece dosyayı kopyalayarak kolayca entegre edebilirsiniz.
*   **Derleme Performansı (Incremental Compilation):** Derleyici (compiler), kaynak dosyalarını değiştirdiğimizde **sadece değiştirilen dosyayı** yeniden derler. 100 dosyalık bir projede tek bir satır değiştirirseniz, sadece o dosya derlenir; geri kalan 99 dosya eski derlenmiş halleriyle kullanılır. Bu, büyük projelerde derleme süresini saatlerden saniyelere düşürür.

## 2. IDE Üzerinde Dosya Yönetimi (Visual Studio 2026 & Code::Blocks)
Kodu birden fazla dosyaya böldüğümüzde, bu dosyaları derleyicinin görebilmesi için projeye doğru şekilde dahil etmemiz gerekir.
*   **Yeni Dosya Ekleme:** Visual Studio'da Çözüm Gezgini (Solution Explorer) penceresinde `Kaynak Dosyaları` (Source Files) klasörüne sağ tıklayıp `Ekle > Yeni Öğe...` (Add > New Item...) diyerek yeni bir `.cpp` dosyası (örneğin `add.cpp`) oluşturulur.
*   **Mevcut Dosyayı Ekleme:** Dosyayı normal klasörden (Dosya menüsünden) oluşturursanız projeye otomatik dahil olmaz. Çözüm Gezgini'nde `Ekle > Mevcut Öğe...` (Add > Existing Item...) diyerek manuel eklenmelidir.
*   *Önemli Not:* Derleme (Build) işlemi başladığında, derleyicinin çıktı penceresinde hem `main.cpp` hem de `add.cpp`'yi derlediğini listelediğini görmelisiniz.

## 3. Derleyicinin (Compiler) Kısa Hafızası ve Davranışı
C++ tasarlanırken, derleyicinin dosyaları tek bir devasa metin olarak görmemesi, her birini **birbirinden tamamen bağımsız (Translation Unit)** olarak okuması kurgulanmıştır.
*   **Amnesia (Hafıza Kaybı):** Derleyici `main.cpp`'yi derlerken, `add.cpp`'de ne yazılı olduğuna dair hiçbir fikri yoktur. Hatta `add.cpp`'yi `main.cpp`'den 1 saniye önce derlemiş olsa bile bunu **hatırlamaz**.
*   **Kasıtlı Tasarım:** Bu unutkanlık bir hata değil, **mimari bir tercihtir**. Böylece dosyalar birbirine paralel (aynı anda) derlenebilir, isim çakışmaları (name collisions) minimize edilir ve sadece değişen dosyalar derlenerek hız kazanılır.

## 4. Dosyalar Arası İletişim: Forward Declaration
Madem derleyici diğer dosyalardaki fonksiyonları göremiyor, `main.cpp` içinden `add.cpp`'deki bir fonksiyonu nasıl çağıracağız? 
İşte burada **Forward Declaration (Ön Bildirim)** devreye girer. 

Derleyiciye aslında şu sözü veririz: *"Ben bu fonksiyonu kullanıyorum, şu an sana gövdesini (definition) veremem ama söz veriyorum bu fonksiyon projenin bir yerlerinde var, sen hata verme ve geç."*

**main.cpp:**
```cpp
#include <iostream>

// Forward Declaration: Derleyiciye fonksiyonun prototipini tanıtıyoruz (Sadece Declaration)
int add(int x, int y); 

int main()
{
    std::cout << "3 + 4 = " << add(3, 4) << '\n'; // Derleyici ikna oldu, hata vermeyecek.
    return 0;
}
```

**add.cpp:**
```cpp
// Asıl tanım (Definition) burada yer alıyor.
int add(int x, int y)
{
    return x + y;
}
```
*Süreç:* Derleyici her iki dosyayı ayrı ayrı başarıyla derler. Daha sonra **Bağlayıcı (Linker)** gelir ve `main.cpp`'deki boş `add` çağrısını, `add.cpp`'deki asıl bellekteki yerine (definition) bağlar.

## 5. Hata Ayıklama Mimarisi (Something went wrong!)
Birden fazla dosyayla çalışırken alınan hataların kaynağını tespit etmek kritik bir mühendislik becerisidir:
*   **Compiler Hatası ("identifier not found" vb.):** `main.cpp` içinde `add()` fonksiyonunu kullandınız ama en üste *Forward Declaration* yazmayı unuttunuz. Derleyici tanımsız bir tanımlayıcı gördüğü an işlemi durdurur.
*   **Linker Hatası ("unresolved external symbol" vb.):** `main.cpp`'ye forward declaration yazdınız (derleme başarılı oldu). Ancak Linker çalışırken asıl gövdeyi (definition) bulamadı. Olası nedenleri:
    1.  `add.cpp` dosyası IDE projesine düzgün eklenmemiştir (Çözüm gezgininde görünmüyordur).
    2.  Yanlış projeye eklenmiştir.
    3.  Dosyanın derlenmesi IDE üzerinden devre dışı bırakılmıştır. (Örn: Visual Studio'da dosya özelliklerinde "Derlemeden Hariç Tut / Exclude from Build" seçeneği "Evet" kalmıştır veya Code::Blocks'ta derleme onay kutuları işaretlenmemiştir).

## 6. Kritik Kural: Asla .cpp Dosyalarını #include Etmeyin!
`main.cpp` dosyasının en üstüne `#include "add.cpp"` **yazılmaz**.
*Neden?* Bunu yaparsanız, derleyici `add.cpp`'nin tüm içeriğini kopyalayıp `main.cpp`'nin içine yapıştırır. Daha sonra projede `add.cpp` ayrı bir dosya olarak da derleneceği için, `add()` fonksiyonu projede **iki kez tanımlanmış (Multiple Definition)** olur. Bu da Tek Tanım Kuralı'nı (ODR) ihlal eder ve Linker hatasına yol açar. `.cpp` dosyaları include edilmez, IDE'ye/derleyiciye ayrı ayrı verilir. (İleride başlık - header dosyaları kullanılacaktır).

---

## Active Recall: Sorular ve Geliştirilmiş Yanıtlar

**Soru 1:** Bütün bir C++ projesini tek bir devasa `main.cpp` dosyasına yazmak yerine neden birden fazla `.cpp` dosyasına (multiple code files) böleriz? Bunun özellikle proje büyüdükçe derleme süresine (compile time) olan etkisi nedir?
**Geliştirilmiş Yanıt:** Projeyi farklı dosyalara bölmek; kodun okunabilirliğini, organizasyonunu ve farklı projelerde yeniden kullanılabilirliğini (reusability) artırır. Ancak donanım/performans tarafındaki en büyük getirisi **artımlı derlemedir (incremental compilation)**. Bir dosyada değişiklik yaptığımızda, derleyici tüm projeyi değil, yalnızca değiştirilen o `.cpp` dosyasını yeniden derler. Bu mekanizma, büyük projelerde saatler sürebilecek derleme işlemlerini saniyelere düşürerek muazzam bir hız kazandırır.

**Soru 2:** Derleyici (compiler), projendeki birden fazla `.cpp` dosyasını derlerken bunları birleştirip tek bir bütün olarak mı okur, yoksa her bir `.cpp` dosyasını birbirinden tamamen habersiz, bağımsız birimler (translation units) olarak mı derler?
**Geliştirilmiş Yanıt:** Derleyici her bir `.cpp` dosyasını **Translation Unit (Çeviri Birimi)** adı verilen, birbirinden tamamen bağımsız ve habersiz adalar olarak derler. Dosyaları birleştirip okumaz. Hatta dosyalardan birini derlediğinde öğrendiği bir fonksiyonu veya değişkeni, bir sonraki dosyayı derlerken tamamen "unutur". Bu mimari sayesinde projeler çok çekirdekli işlemcilerde paralel (aynı anda) derlenebilir ve isim çakışmalarının önüne geçilir.

**Soru 3:** Derleyicinin dosyaları okuma mantığını göz önüne aldığında; `dosya1.cpp` içindeki bir kodun, `dosya2.cpp` içindeki bir fonksiyonu kullanabilmesi için derleyiciyi nasıl ikna etmemiz gerekir? Dün öğrendiğin `forward declaration` burada nasıl bir rol oynar?
**Geliştirilmiş Yanıt:** Derleyici, okuduğu dosyada daha önce görmediği hiçbir şeyi tanımaz. `dosya1.cpp`'nin içinden `dosya2.cpp`'deki bir fonksiyonu çağırabilmek için `dosya1.cpp`'nin en üstüne bir **Forward Declaration (Ön Bildirim)** yazarız. Bu hamle derleyiciye; "Bu fonksiyonun parametreleri ve dönüş tipi şunlardır, gövdesi (definition) başka bir yerde, sen sadece söz dizimini (syntax) kontrol et ve hata verme" diyerek onu ikna eder. Derleyici bu güvenceyle kendi işini bitirir, eksik gövdeyi bulma işini ise Bağlayıcıya (Linker) devreder.

**Soru 4:** Tek Tanım Kuralı (ODR): Yanlışlıkla iki farklı `.cpp` dosyasında tamamen aynı isimde ve aynı işlevi yapan bir fonksiyon tanımlarsan (definition), hatayı derleyici (compiler) mi verir yoksa bağlayıcı (linker) mı? Neden?
**Geliştirilmiş Yanıt:** Hatayı **Bağlayıcı (Linker)** verir. Çünkü derleyicinin hafızası yoktur ve her dosyayı bağımsız bir ada olarak derler. Birinci dosyayı derlerken o fonksiyonu görür ve geçer, ikinci dosyayı derlerken aynı fonksiyonu sanki ilk kez görüyormuş gibi derler ve yine hata vermeden geçer. Her iki dosyanın da derleme işlemi başarıyla tamamlanır. Ancak en son aşamada Linker devreye girip bu bağımsız parçaları tek bir çalıştırılabilir programa (executable) dönüştürmek istediğinde, aynı isimde iki farklı fonksiyon gövdesi bulur. Hangisini kullanacağını bilemediği için (ODR ihlali) işlemi durdurur ve Linker hatası verir.
