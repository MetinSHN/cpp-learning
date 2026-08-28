# C++ Notları: Bölüm 2.3 — Void Fonksiyonlar (Değer Döndürmeyen Fonksiyonlar)

## 1. Void Return Type Nedir?
Derleyiciye fonksiyonun geriye bir sonuç (değer) döndürmeyeceğini söylemek için dönüş türü (return type) olarak `void` kullanırız. Bir değer döndürmeyen fonksiyonlara "non-value returning function" veya "void function" denir.

```cpp
#include <iostream>

// void, bu fonksiyonun çağrıldığı yere bir değer bırakmayacağı anlamına gelir.
void printHi()
{
    std::cout << "Hello World!" << '\n';
    // Herhangi bir değer döndürmüyoruz.
}

int main()
{
    printHi(); // Fonksiyon bir eylem gerçekleştirdi (ekrana yazdırdı) ve bitti.
    return 0;
}
```

## 2. Void Fonksiyonlarda 'return' Kullanımı ve "Early Return" Kavramı
Bir `void` fonksiyonu, kod bloğunun sonuna ulaştığında (kapanış süslü parantezi `}`) **otomatik olarak** kendisini çağıran yere (caller) geri döner. Bu nedenle fonksiyonun en sonuna `return;` yazmak geçerlidir ama gereksizdir. (Not: return statement bir değersiz kullanılabilir. Ama gereksizdir.)

```cpp
void printHi()
{
    std::cout << "Hello World!" << '\n';
    return; // Geçerli bir kullanımdır ancak fonksiyonun sonunda olduğu için GEREKSİZDİR.
}
```

**ÖNEMLİ (Early Return):**
Yalnız başına kullanılan `return;` ifadesi her zaman gereksiz değildir. Eğer fonksiyonun ortasında bir şart kontrolü yapıyorsak ve fonksiyonun geri kalan kodlarının **çalışmamasını** istiyorsak, akışı anında kesip caller'a dönmek için `return;` kullanırız. Buna **Early Return (Erken Çıkış)** denir. İleride çok işimize yarayacaktır.

**Örnek:**
```cpp
void printPositive(int x)
{
    if (x < 0) {
        std::cout << "Hata: Sadece pozitif sayilar!\n";
        return; // Sayı negatifse fonksiyonu burada kes ve geri dön! (Erken Çıkış)
    }
    
    std::cout << "Sayiniz: " << x << '\n';
}
```

## 3. Void Fonksiyonların İfadelerde (Expressions) Kullanımı
Bazı C++ komutları çalışabilmek için kesinlikle bir değere ihtiyaç duyar. Örneğin `std::cout` ekrana basacak bir "veri" ister. `void` fonksiyonlar bir değer üretmediği için değer beklenen yerlerde kullanılamazlar. Fonksiyonun kendisi çağırılırken bir değer gerekmez, ancak değer gerektiren yerlerde derleyici hatası alırız.

```cpp
#include <iostream>

void printHi()
{
    std::cout << "Hi" << '\n';
}

int main()
{
    std::cout << 5; // sorun yok: 5 sabit bir değerdir ve değer isteğini karşılar.
    
    printHi(); // DOĞRU: Sadece fonksiyonu çağırdık, bir değer beklemiyoruz.

    std::cout << printHi(); // HATA (Compile error): printHi() geriye hiçbir şey vermez, cout neyi yazdıracak?
    return 0;
}
```

## 4. Void Fonksiyondan Değer Döndürmeye Çalışmak
Derleyiciye `void` sözcüğü ile "ben değer döndürmeyeceğim" sözünü verdikten sonra, `return 5;` gibi bir değer döndürmeye çalışırsak derleyici hata verir (Compile error).

```cpp
void printHi() 
{
    std::cout << "In printHi()" << '\n';
    return 5; // HATA (Compile error): void fonksiyon bir değer döndüremez.
}
```

---

# Günün Pratik Soruları ve Analizi (Day 16)

**Soru 1:** Derleyici Testi: Visual Studio'da bir `void` fonksiyon oluştur ve içine `return 5;` yazıp derlemeye çalış. Derleyici sana tam olarak hangi hata mesajını veriyor ve sence neden bu işlemi bu kadar kesin bir şekilde reddediyor?
*   **Senin Cevabın:** Hata verir çünkü void fonksiyonu değer döndürmez.
*   **Mentor Analizi:** Kesinlikle doğru. C++ tip güvenliği (type safety) konusunda çok katıdır. Fonksiyonun imzasında `void` sözünü verdiysen, derleyici bu sözün dışına çıkmana izin vermez.

**Soru 2:** Gerçek Dünya Mantığı: CS2'de AWP ile açıyı tuttun ve sol tıka bastın. Arka planda silahın patlamasını ve merminin çıkmasını sağlayan "ateş etme" eylemini başlatan fonksiyon sence `int` gibi bir değer mi döndürmelidir, yoksa `void` mi olmalıdır? Neden?
*   **Senin Cevabın:** voiddir çünkü bir değer döndürmüyor da ekrana bir şey yazar gibi bir eylem yapıyor.
*   **Mentor Analizi:** Mükemmel bir mühendislik benzetmesi! Ateş etme fonksiyonu bir eylem gerçekleştirir (mermiyi çıkarır, sesi çalar, cephaneyi 1 azaltır). Geriye hesaplanmış bir matematiksel sonuç döndürmesi gerekmez. Fonksiyonların bir "hesap makinesi" gibi çalışabileceği gibi bir "aksiyon tetikleyicisi" de olabileceğini çok iyi anlamışsın.

**Soru 3:** Akış Kontrolü: `void` fonksiyonun içine sadece `return;` yazarsak programın akışına ne olur? Bu kullanım sence hangi durumlarda işimize yarayabilir?
*   **Senin Cevabın:** Bir şey döndürmediğini belirtir fonksiyonu bitirir ve callera geri döndürür ama bir işimize yaramaz gereksizdir.
*   **Mentor Analizi:** İlk kısım (fonksiyonu bitirir ve caller'a döner) tamamen doğru. Ancak **"gereksizdir" kısmı eksik**. En sona yazmak gereksizdir ancak fonksiyonu bir hata anında yarıda kesip iptal etmek için (Early Return) kullanmak hayat kurtarır (Yukarıdaki 2. maddede eklenen örneği inceleyebilirsin).
