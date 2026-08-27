# Bölüm 2.2 — Function Return Values (Değer Döndüren Fonksiyonlar)

## 1. Return Values (Dönüş Değerleri)
Kullanıcı kendi oluşturduğu bir fonksiyon yazdıysa, o fonksiyonun çağrıldığı yere (caller) bir değer döndürüp döndürmeyeceğini belirlememiz gerekir. Değer döndüreceksek iki şeye ihtiyacımız vardır:

1. **Dönüş Tipi (Return Type):** Fonksiyonun ne tür bir değer döndüreceğini belirtmeliyiz. (`returnType functionName(){}` yapısındaki `returnType` kısmı).
2. **Return İfadesi (Return Statement):** Fonksiyonun içinde döndüreceğimiz değeri belirtmek için `return` anahtar kelimesi (keyword) kullanılır. Ardından döndürülecek ifade (`return expression`) gelir ve `;` ile sonlandırılır.

### "Return by Value" Süreci
`return` ifadesi kullanıldığında şunlar gerçekleşir:
- `return` ifadesi değerlendirilerek bir değer üretilir.
- Bu değer **kopyalanarak** (return value) çağrıldığı yere (caller) aktarılır.
- Fonksiyonun çalışması sona erer ve kontrol tekrar `caller`'a geçer.
- Bu değere ve kopyalama işlemine **"return by value"** denir.

**Örnek Program:**
```cpp
#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer : ";
    int num{};
    std::cin >> num;
    return num; // num değerinin bir kopyasını caller'a döndürür
}

int main()
{
    // getValueFromUser()'dan dönen değer num değişkenine atanır
    int num{ getValueFromUser() };
    std::cout << num << " doubled is: " << num * 2 << '\n';
    
    // Bu çağrı çalışır, değer döndürür ama dönen değer kullanılmadığı (veya ekrana yazdırılmadığı) için kaybolur.
    getValueFromUser();

    return 0;
}
```

> **Not:** Çağıran taraf (caller), dönüş değerini bir değişkende saklamazsa veya `std::cout` aracılığıyla doğrudan kullanmazsa, dönen değer bellekte değerlendirilir ve sonra atılır (kaybolur).

---

## 2. main() Fonksiyonunu Yeniden İncelemek

Program başlatıldığında işletim sistemi `main()` fonksiyonunu çağırarak yürütmeyi başlatır. C++'ta `main()` fonksiyonu için iki katı kural vardır:
1. `main()` fonksiyonu kesinlikle **`int` değer döndürmelidir**.
2. Programın içinde `main()` fonksiyonunu açıkça çağırmak **yasaktır** (Compile error verir).

### Status Codes (Durum Kodları)
`main()` fonksiyonundan döndürdüğümüz bu `int` değere "status code", "exit code" veya "return code" denir. Bu kod, işletim sistemine programın nasıl sonlandığını bildirir.
- **`0`**: Programın başarıyla, beklenen şekilde çalıştığını ve normal olarak sonlandığını gösterir.
- **Sıfırdan farklı bir değer**: Genellikle bir hatayı belirtir.

### Undefined Behavior (Tanımsız Davranış)
Eğer bir fonksiyon `void` dışında bir dönüş tipine (örneğin `int`) sahipse, **mutlaka bir değer döndürmek zorundadır**. Değer döndürmezse derleyici hatası veya "Undefined Behavior" (Tanımsız Davranış) oluşur.

> **İstisna:** `main()` fonksiyonu bir `int` döndürmek zorunda olsa da, eğer `return` ifadesi yazmayı unutursanız, derleyici otomatik (örtük) olarak `return 0;` ekler. Ancak iyi bir programlama alışkanlığı olarak `main()`'in sonuna her zaman `return 0;` açıkça yazılmalıdır. *(Not: Önceki derslerde de bunu konuşmuştuk, aynen geçerli).*

---

## 3. Fonksiyonların Sınırları ve Dokümantasyon

- **Tek Bir Değer Döndürme:** Değer döndüren bir fonksiyon, her çağrıldığında `caller`'a yalnızca **bir tane değer** döndürebilir. (Bu kısıtlamayı aşmanın yollarını ileride öğreneceğiz).
- **Dönüş Değerinin Anlamı:** Bir fonksiyonun döndürdüğü değerin ne anlama geldiğine (status code mu, hesaplanan bir sonuç mu?) fonksiyonu yazan kişi karar verir. Bu nedenle fonksiyonları yorum satırlarıyla belgelemek çok önemlidir.

```cpp
// Kullanıcıdan bir değer girmesini ister.
// Dönüş değeri, kullanıcının klavyeden girdiği tam sayıdır (int).
int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input; 
}
```

---

## 4. Reusing Functions (Fonksiyonları Yeniden Kullanmak) ve DRY İlkesi

İyi programlamanın en temel ilkelerinden biri **DRY (Don't Repeat Yourself - Kendini Tekrar Etme)** ilkesidir.

Aynı kodu tekrar tekrar kopyalayıp yapıştırmak yerine, fonksiyonlar oluşturup gerektiğinde bu fonksiyonları birden fazla kez çağırırız.

```cpp
#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer : ";
    int num{};
    std::cin >> num;
    return num;
}

int main()
{
    // Aynı fonksiyonu iki kez çağırarak kodu tekrar etmekten kurtulduk
    int num1{ getValueFromUser() };
    int num2{ getValueFromUser() };
    
    std::cout << num1 << " ve " << num2 << " sayilarinin toplami : " << num1 + num2 << '\n';

    return 0;
}
```

> **Özet Kural:** 
> - Değişkenler: Tekrar kullanılacak *verileri* saklar.
> - Fonksiyonlar: Tekrar kullanılacak *kod bloklarını (işlemleri)* saklar.
> - Döngüler: Bir işlemi peş peşe defalarca *tekrarlamayı* sağlar.

---

## 5. Active Recall ve Öğrenme Değerlendirmesi (Day 15)

**Soru 1: Dönüş Tipi Farkı (`void` vs `int`)**
*Senin Cevabın:* "void bir şeyi döndürmez int ise kesinlikle döndürmelidir ve bu da sayı olmalıdır ayrıca sadece 1 değer döndürebilir"
*Değerlendirme:* 🎯 **Mükemmel.** Tamamen doğru anladın. `void` sadece işi yapar ve döner, `int` ise somut bir veri (tam sayı) üretip geri vermek zorundadır ve limit her zaman 1 değerdir.

**Soru 2: Yürütme Akışı (Execution Flow)**
*Senin Cevabın:* "return değeri bir sonucu alır caller dediğimiz yere aktarır ve callerdan devam ederiz işleme"
*Değerlendirme:* 🎯 **Çok net.** Programın akışının kopmadığını, sadece geçici olarak başka bir adrese gidip, sonucu alıp kaldığı yerden (caller'dan) devam ettiğini kavramışsın.

**Soru 3: Caller'ın Rolü**
*Senin Cevabın:* "Döndürdüğümüz değer neyse ona uygun kullanabilir. Atamak zorunda değildir ama kolaylık olması açısından atayabilir."
*Değerlendirme:* 🎯 **Tam isabet.** Caller değeri ister bir değişkene atar (`int x = foo();`), ister doğrudan yazdırır (`cout << foo();`), isterse de hiçbir şey yapmadan çöpe atar (sadece `foo();` yazarak). Kontrol caller'dadır.

**Soru 4: Tasarım Mantığı (Return vs Cout)**
*Senin Cevabın:* "Bazı yerlerde biz sadece o değerle ilgili bir şeyler yaparız ekrana yazdırırsak tam olarak o değeri çekemeyiz."
*Değerlendirme:* 🎯 **Harika mühendislik bakış açısı.** Eğer bir fonksiyon ekrana yazdırma (cout) ile sınırlandırılırsa, o fonksiyonu arka planda sadece hesaplama yapmak istediğimiz bir yerde kullanamayız. `return` bize veriyi saf haliyle verir, biz o veriyle ne yapacağımıza (yazdıracak mıyız, toplayacak mıyız, dosyaya mı kaydedeceğiz) karar veririz. DRY ilkesinin kalbidir.
