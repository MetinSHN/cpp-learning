# C++ Fonksiyonlara Giriş (LearnCpp 2.1) - Çalışma Notları

**Bağlam:** Bilgisayar Mühendisliği 4 Yıllık Gelişim Sistemi - Day 14
**Konu:** LearnCpp Bölüm 2.1 (Introduction to Functions)

---

## 1. Fonksiyon (Function) Nedir ve Neden Kullanılır?

**Function (Fonksiyon):** Belirli bir görevi yerine getirmek üzere tasarlanmış, tekrar tekrar kullanılabilen bir kod sekansıdır (dizisidir).

Her C++ programı çalışmaya başlamak için bir `main()` fonksiyonuna sahip olmak zorundadır. Ancak her şeyi sadece `main()` fonksiyonunun altına yazarsak, büyük projelerde kodun kontrolü ve okunabilirliği aşırı zorlaşır. Bu yüzden farklı fonksiyonlar kullanarak büyük problemleri daha küçük parçalara ayırırız. Bu yaklaşım işimizi ve programı yönetmeyi çok daha kolaylaştırır.

Standart C++ kütüphanesi (`<iostream>` gibi) kullanabileceğimiz birçok hazır fonksiyonla birlikte gelir. Örneğin kodumuzun başına `#include <iostream>` yazdığımızda, aslında o kütüphanenin içindeki kodları derleme aşamasında (preprocessor aracılığıyla) kendi kodumuza yapıştırmış (dahil etmiş) oluyoruz. 

Hazır kütüphanelerin dışında, kendi oluşturduğumuz fonksiyonlara **User-Defined Functions (Kullanıcı Tanımlı Fonksiyonlar)** denir.

---

## 2. C++ Programlarında Yürütme Akışı (Kitap Analojisi)

Programın çalışırken fonksiyonlar arasında nasıl gidip geldiğini anlamak için şu analojiyi kullanabiliriz:

> Bir kitap okuyorsun ve bir anda aklına birini araman gerektiği geldi. Kitabına bir ayraç koyarak kapatıp aramanı yaptıktan sonra, tekrardan ayracın olduğu yeri açıp kitabına kaldığın yerden devam ettiğini düşün.

Benzer mantık C++ programları için de geçerlidir:
1. Bir program çalışırken bir fonksiyon çağırıldığında, akış o fonksiyona gider.
2. O fonksiyonun içindeki sekansı (yönergeleri) sırayla yürütür.
3. İşlem bittikten sonra kaldığı yerden devam eder.

**Function Call (Fonksiyon Çağrısı):** Bu işlemi CPU'ya iletir. CPU, o anki yürütmeyi (durumu) durdurur, kaldığı yere bir nevi "işaret" koyar ve diğer fonksiyonu çalıştırır. Fonksiyon görevini tamamladıktan sonra bir `return` (geri dönüş) işlemi gerçekleşir ve CPU işaret koyduğu yerden çalışmaya devam eder.

---

## 3. Caller ve Callee Kavramları

Bir fonksiyonun çağrılması (invocation / uygulama) işleminde iki temel aktör vardır:

*   **Caller (Çağıran):** Başka bir fonksiyona emir veren veya işlem sırasını başka bir fonksiyona devreden kod parçasıdır (örneğin diğer fonksiyonları çağıran bir `main()` fonksiyonu).
*   **Callee (Çağrılan):** Caller tarafından çağrılan, verilen işi yapıp sonucunda kontrolü (veya bir değeri) geri döndüren fonksiyondur.

**Örnek:**
```cpp
#include <iostream>

// Bu fonksiyon CALLEE (çağrılan) rolündedir
void selamVer() {
    std::cout << "Merhaba!";
}

int main() {
    // Bu satırda main() fonksiyonu CALLER (çağıran) rolündedir
    selamVer(); 
    return 0;
}
```

---

## 4. Fonksiyonun Yapısı

Değişkenlerin isimleri olduğu gibi, fonksiyonların da isimleri vardır. Bir fonksiyon temel olarak iki kısımdan oluşur:

1.  **Function Header (Fonksiyon Başlığı):** Fonksiyonun ismini, döndüreceği veri tipini (return type) ve alacağı parametreleri derleyiciye bildirdiğimiz kısımdır.
2.  **Function Body (Fonksiyon Vücudu):** Köşeli parantezler `{ }` arasında kalan kısımdır. Fonksiyonun yapacağı işlemlerin (yönergelerin) yer aldığı asıl kod bloğudur.

```cpp
returnType functionName() // Burası fonksiyonun başlığıdır (Function Header)
{
    // Burası fonksiyonun gövdesidir (Function Body).
    // Fonksiyonun yapacağı işlemler burada yer alır.
}
```

**Kritik Kural:** C++'ta bir fonksiyon çağırılmadan (kullanılmadan) önce derleyici tarafından mutlaka tanımlanmış (veya bildirilmiş) olmalıdır. (Yukarıdan aşağıya okuma mantığı).

---

## 5. Fonksiyonların Çağrılması

### 5.1. Bir Fonksiyonu Birden Fazla Kez Çağırmak
Fonksiyonların en güzel yanlarından biri, aynı fonksiyonu kod içinde istediğiniz kadar tekrar çağırabilmenizdir. Bu, kod tekrarını önler (DRY - Don't Repeat Yourself prensibi).

```cpp
#include <iostream>

void doA()
{
    std::cout << "A fonksiyonu calisiyor.\n";
}

int main()
{
    std::cout << "main() fonksiyonu calisiyor.\n";
    doA();
    doA(); // İstediğimiz kadar çağırabiliriz
    std::cout << "Tekrar main() fonksiyonu calisiyor.\n";

    return 0;
}
```

### 5.2. Fonksiyon İçinden Başka Fonksiyon Çağırmak (Zincirleme)
Sadece `main()` fonksiyonu değil, herhangi bir fonksiyon da başka bir fonksiyonu çağırabilir.

```cpp
#include <iostream>

void doB()
{
    std::cout << "Simdi de B fonksiyonu calisiyor.\n";
}

void doA()
{
    std::cout << "A fonksiyonu calisiyor\n";
    doB(); // doA, doB'yi çağırıyor (doA caller, doB callee oldu)
    std::cout << "A fonksiyonu bitiyor.\n";
}

int main()
{
    std::cout << "main() fonksiyonu calisiyor.\n";
    doA();
    std::cout << "Tekrar main() fonksiyonu calisiyor.\n";

    return 0;
}
```

---

## 6. İç İçe (Nested) Fonksiyonlar Desteklenmez!

Bir fonksiyonun gövdesi (body) içinde tamamen yeni bir fonksiyon tanımlamaya **"nested function" (iç içe fonksiyon)** denir. Bazı programlama dillerinin aksine, **C++ dilinde fonksiyonlar iç içe tanımlanamaz.** Her fonksiyon bağımsız olarak kendi alanında (genellikle global scope) tanımlanmalıdır.

**Hatalı (Yasadışı) Kullanım:**
```cpp
#include <iostream>

int main()
{
    // HATA: main() fonksiyonunun içinde başka bir fonksiyon TANIMLANAMAZ!
    void foo()
    {
        std::cout << "Merhaba!";
    }

    foo();

    return 0;
}
```

**Doğru Kullanım:**
```cpp
#include <iostream>

// Fonksiyon dışarıda tanımlanır
void foo()
{
    std::cout << "Merhaba!";
}

int main()
{
    // main() sadece çağırır
    foo();

    return 0;
}
```

---

## 7. Günün Değerlendirme Soruları ve Cevaplarım

**Soru 1: Neden böyle tasarlanmıştır? Tüm kodumuzu neden sadece main() fonksiyonunun içine alt alta yazıp geçmiyoruz? Fonksiyon kullanmak bize ne gibi avantajlar sağlar?**
**Cevap:** Büyük programlarda her şeyi tek bir fonksiyonun altına yazmak kontrolü zorlaştırır. Kodları yeni fonksiyonlarla küçük parçalara ayırmak, işimizi ve kodun yönetimini çok daha kolaylaştırır.

**Soru 2: Nasıl çalışır? "Caller" ve "Callee" kavramlarını nasıl açıklarsın?**
**Cevap:** Caller, başka bir fonksiyona emir veren (onu çağıran) taraftır; örneğin `main()` fonksiyonu. Callee ise çağrılıp işini yapan fonksiyondur. Callee işini bitirdikten sonra, Caller (çağıran fonksiyon) kaldığı yerden çalışmaya devam eder.

**Soru 3: main() fonksiyonunun içine başka bir fonksiyon yazmaya çalışırsan C++ derleyicisi buna nasıl tepki verir?**
**Cevap:** Diğer bazı dillerin aksine C++'ta bu yapı (nested functions) desteklenmediği için derleyici hata verir ve kod çalışmaz.

**Soru 4: Geriye değer döndürmeyen ve sadece ekrana mesaj yazdıran basit bir fonksiyon yazıp main() içinden çağır.**
**Cevap:**
```cpp
#include <iostream>

void mesajYazdir()
{
    std::cout << "Hacettepe BM'ye selam!\n";
}

int main()
{
    std::cout << "Su an main() fonksiyonundasin.\n";
    mesajYazdir();
    std::cout << "Su an tekrar main() fonksiyonundasin.\n";

    return 0;
}
```
