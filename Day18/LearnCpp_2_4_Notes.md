# Introduction to Function Parameters and Arguments

## Function Parameters and Arguments
**Function parameter (Fonksiyon parametresi):** Fonksiyon başlığında (signature) tanımlanan ve fonksiyonun çalışması için dışarıdan beklediği verileri tutan yer tutucu değişkenlerdir. Bu değişkenler, fonksiyon çağrıldığında caller (çağıran) tarafından gönderilen değerler ile başlatılır (initialize edilir).

Örnek yapı: `returnType functionName(parameter1, parameter2) {}`

**Argument (Argüman):** Bir fonksiyon çağrısı yapıldığında, çağıran (caller) tarafından fonksiyona fiili olarak aktarılan değerdir.

> **Not:** Şu anki bilgilerimize göre `main()` fonksiyonu parametre almaz (ileride komut satırı argümanları alan farklı bir versiyonunu göreceğiz).

```cpp
#include <iostream>

// Fonksiyon Tanımı (Definition)
// 'en' ve 'boy' birer PARAMETREDİR. Bellekte henüz yerleri yoktur, sadece yer tutucudur.
int alanHesapla(int en, int boy) {
    return en * boy;
}

int main() {
    int x = 5;
    int y = 10;

    // Fonksiyon Çağrısı (Call)
    // 'x' ve 'y' (veya doğrudan 5 ve 10 değerleri) birer ARGÜMANDIR.
    // Fonksiyon çalışırken bu değerler parametrelere kopyalanır.
    int sonuc = alanHesapla(x, y); 
    
    std::cout << "Alan: " << sonuc << std::endl;
    return 0;
}
```

## How Parameters and Arguments Work Together
Derleyici, argümanları parametrelerle sırasına göre eşleştirir (ilk argüman ilk parametreye, ikinci argüman ikinci parametreye). 
Argüman olarak gönderilen değer, ilgili parametre değişkenine kopyalanır. Parametre artık o değerin bir kopyasını tutar ve fonksiyon içinde bağımsız bir değişken olarak yaşar. Bu argüman değerinin parametreye kopyalanması sürecine **"pass by value" (değere göre aktarım)** denir. Bu şekilde çalışan parametrelere de "value parameters" adı verilir.

## Using Return Values as Arguments
Bir fonksiyondan dönen değeri (return value), doğrudan başka bir fonksiyona argüman olarak aktarabiliriz.

```cpp
#include <iostream>

void getDouble(int num)
{
    std::cout << "Double of " << num << " is: " << num * 2;
}

int getValueFromUser() 
{
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;
    return num; // Dönüş değeri
}

int main()
{
    // getValueFromUser()'dan dönen değer, getDouble() fonksiyonuna argüman olarak gider.
    getDouble(getValueFromUser());

    return 0;
}
```

## How Parameters and Return Values Work Together
Hem parametreleri hem de dönüş değerini bir arada kullanarak; dışarıdan veriyi girdi olarak alan, bu veriyle belirli hesaplamalar yapan ve sonucu tekrar çağırana (caller) döndüren esnek fonksiyonlar oluşturabiliriz.

```cpp
#include <iostream>

int add(int x, int y) 
{
    return x + y;
}

int main()
{
    std::cout << add(4, 5);
    
    return 0;
}
```

## Unreferenced Parameters and Unnamed Parameters
Bazı durumlarda, fonksiyon gövdesinde hiç kullanılmayan parametrelere sahip fonksiyonlarla karşılaşabilirsiniz. Bunlara **“unreferenced parameters” (referanslanmamış/kullanılmayan parametreler)** denir.

```cpp
void doSomething(int count) // warning: unreferenced parameter count
{
    // Bu fonksiyon eskiden count parametresini kullanıyordu ama artık kullanmıyor.
}

int main()
{
    doSomething(4);
    return 0;
}
```
Böyle bir durumda modern derleyiciler size uyarı (warning) verecektir.

Bir fonksiyon tanımında, parametre adı vermek isteğe bağlıdır. Bu nedenle, bir fonksiyonun belirli bir tipte parametre alması gerektiği halde o parametrenin fonksiyon içinde kullanılmadığı durumlarda, değişken adını silebilirsiniz. Sadece veri tipinin kaldığı bu yapıya **"unnamed parameter" (adsız parametre)** denir. Bu kullanım, derleyicinin uyarı vermesini engeller:

```cpp
void doSomething(int) // ok: adsız parametre uyarı üretmez
{
}
```
Google C++ stil kılavuzu, bu isimsiz parametrenin ne işe yaradığını belgelemek için yorum satırı kullanılmasını önerir:

```cpp
void doSomething(int /*count*/)
{
}
```

**Soru:** Değeri kullanılmayan bir parametreye neden ihtiyaç duyarız?
**Cevap:** Fonksiyonu güncellerken içindeki bir parametrenin kullanımını kaldırmış olabilirsiniz. Ancak bu fonksiyon projenin farklı yerlerinden (belki yüzlerce kez) argüman gönderilerek çağrılıyor olabilir. Parametreyi tamamen silerseniz, o fonksiyonu çağıran tüm eski kodlar hata verir (geriye dönük uyumluluk kırılır). Kodu kırmamak veya ileride eklenecek bir özellik için yer tutucu bırakmak amacıyla parametre tutulur, adı silinerek uyarı engellenir.

---

## Active Recall (Soru & Cevap)

**Soru 1:** Parametre (Parameter) ve Argüman (Argument) arasındaki teknik fark nedir?
**Cevap:** Parametre fonksiyonun başlığında (tanımında) yer alan ve gelecek değeri bekleyen değişkendir. Argüman ise, fonksiyon çağrılırken caller (çağıran) tarafından bu parametrelere gönderilen gerçek değerlerdir.

**Soru 2:** Bir fonksiyon birden fazla parametre alıyorsa, argümanları gönderirken sıralamanın bir önemi var mıdır? Derleyici hangi argümanın hangi parametreye ait olduğunu nasıl anlıyor?
**Cevap:** Evet, kesinlikle vardır. Derleyici argümanları parametrelere yazılış sırasına göre (pozisyonel olarak) eşleştirir. İlk gönderilen argüman ilk parametreye, ikinci argüman ikinci parametreye kopyalanır.

**Soru 3:** Argüman olarak gönderdiğin bir değer, fonksiyonun parametresine aktarıldığında arka planda tam olarak ne gerçekleşiyor?
**Cevap:** Caller'dan gönderilen argümanın değeri, sırasına uygun olan parametre değişkenine kopyalanır ve o değişken bu değerle başlatılmış olur. C++'taki bu kopyalama sürecine "pass by value" (değere göre aktarım) denir.
