# LearnCpp 1.5 - The input/output library

The input/output library: C++ standart kütüphanesinin bir parçasıdır. inputu klavyeden aldığımız değerle outputu da veriyi konsola dökmek olarak basitleştirebiliriz. "io" part diyerek de kısaltırız. <iostream> dediğimiz kütüphaneden de görüyoruz. 

Iostream kütüphanesinin işlevlerini kullanabilmemiz için herhangi bir kod dosyasının en üstünde #include <iostream> olarak kütüphaneyi dahil etmemiz gerekir.

std::cout: Verileri konsola metin olarak göndermemizi sağlayan komuttur. cout "character output" olduğunu önceki derslerde öğrenmiştim.   

insertion operator (<<) yani ekleme operatörü dediğimiz operatör yardımıyla da göndereceğimiz metni bu operatörün sağına yazarak gönderiyoruz. Bu operatör yardımıyla sayıları hatta değişkenleri de gönderebiliyoruz.

Bu operatörü aynı satıra birden fazla öge yazdırmak için tek bir satırda birden fazla da kullanabiliyoruz. Örn:

```cpp
std::cout << "Hello" << " world!"; // "Hello world!" yazar ekrana

int x{ 5 }, y = 6;
std::cout << x << " " << y; // "5 6" yazar ekrana

int z { 5 }; // (Not: Çakışmaması için x yerine z yapıldı)
std::cout << "Yaşınız: " << z;
```

<< operatörünü (ve >> operatörünü), verileri belirtilen yönde taşıyan bir konveyör bandı olarak hayal edebiliriz. << dışarıyı gösterirken >> içeriyi gösteriyor olarak kodlayabilirsin aklında. Benim kodlamam: std::cin içeriyi bahsettiği için buna doğru yönlenmesi için >>, std::cout dışarıysa konsolun dışına yani << olarak kodladım.

Using std::endl to output a newline: Bir şeyleri yazacağız ama aynı satırda değil de ayrı satırlarda olmasını istiyorsak bu yapıyı kullanırız buna "newline" yani "satır sonu" denir ve bizi bir sonraki satıra taşır. Kullanımı ise:

```cpp
std::cout << "Merhaba" << std::endl;
std::cout << "Benim adım Metin";
```

std::cout is buffered: İfadeler konsola gönderilirken belirli bir sıraya girerler ama hemen gitmezler. Bu talepleri toplamak için ayrılmış bellek bölgesine "buffer" denir. Buradan da konsola aktarılırlar buna da flushed denir.

Tampon aktarılmadan programda bir çökme meydana gelirse bu sıradaki diğerlerinin gönderilmeyeceği anlamına gelir.

Tamponlu aktarımın zıttı tamponsuzdur. Tamponsuzda her veri doğrudan aktarılır.

Verilerin arabelleğe yazılması hızlıdır lakin çıktı aygıtına aktarılması ona göre biraz daha yavaştır. Arabellekleme yani buffering bunun performansını bir nebze artırabilir.

std::endl vs \n: std::endl'ı kullanması genellikle verimsizdir çünkü 2 iş yapar biri satırı bitirmek yeni satıra geçmek 2.si de tamponu boşaltma işlemi yapmak ki bu da yavaştır. Bu komutu birden fazla kullanırsak hem verimsiz olur hem de yavaş çalışır ve gereksizdir. Bu işlem yerine özel bir sembol olan "\n" ifadesini kullanırız. Bunu PHP'de de kullanıyorduk biliyorum. Bu işlem tampondan boşaltma işlemi yapmadığı için daha hızlıdır ve kodda kullanma olarak da daha hızlı ve pratiktir ve iki tırnak içine de yerleştirilebilir. Kullanımına bazı örnekler:

```cpp
std::cout << "Merhaba" << '\n'; // tek tırnak içinde kullanımı (tavsiye edilen)
std::cout << "Ben Metin" << "\n"; // iki tırnak içinde kullanımı (tavsiye edilmez ama kullanılabilir)
std::cout << "Bitti\n"; // iki tırnağın içinde yazıyla beraber kullanımı (tavsiye edilen)
```

bu özel sembolüm /n gibi ya da ' \n' '.\n' gibi kullanımları hatalar doğurabilir.

std::cin: Karakter girişi "character input" anlamına gelir. Klavyeden gelen girdiyi okur ve genellikle de ">>" çıkma operatörünü kullanırız. Bu değişken daha sonra başka değişkenlerle kullanılabilir.

1. 
```cpp
#include <iostream>

int main()
{
    std::cout << "Simdi ise bir rakam girin: "; // Rakam girmesini istedik

    int a{}; // Value-initialization olarak başlattık 

    std::cin >> a; // Klavyeden gelecek olan değeri çektik

    std::cout << a << " rakamini girdiniz.\n";

    return 0;
}
```

2. 
```cpp
#include <iostream>

int main()
{

    std::cout << "Şimdi ise 2 rakam girin arada boşlukla ";

    int b{}; // ilk rakam
    int c{}; // 2. rakam

    std::cin >> b >> c; // 2 rakamı burada çekiyoruz

    std::cout << b << " ve " << c << " rakamlarını girdiniz.";

    return 0;
}