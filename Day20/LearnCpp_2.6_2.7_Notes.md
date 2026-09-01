# LearnCpp 2.6 - Fonksiyonların Kullanım Amaçları ve Verimlilik

## Neden Fonksiyon Kullanmalıyız?
Basit programlarda her şeyi `main()` fonksiyonunun içine koyabiliriz. Ancak programlar uzadıkça, bu durum kodun karmaşıklaşmasına neden olur. Fonksiyon kullanmak:
* Kodları **küçük ve yönetilebilir parçalara** ayırarak işimizi kolaylaştırır.
* **Kod tekrarını azaltır**.
* Fonksiyonlar bağımsız oldukları için değişiklik yapılmadığı sürece tekrar tekrar test edilmelerine gerek kalmaz (test edilecek kod miktarını azaltır).
* Genişletilebilirlik sağlar: Programda bir değişiklik/ekleme yapılacağında her yeri değiştirmek yerine sadece ilgili fonksiyonu güncellemek yeterlidir.
* Soyutlama (Abstraction) sağlar: Bir fonksiyonu kullanmak için sadece adını (ve parametrelerini) bilmemiz yeterlidir, iç işleyişini bilmek zorunda değiliz. Bu, dış kütüphaneleri kullanırken büyük kolaylık sağlar.

## Fonksiyonları Verimli Kullanmak
Birden fazla ifadenin tekrar ettiği durumlarda fonksiyonlar kullanılmalıdır. İdeal olarak, **bir fonksiyon yalnızca tek bir görevi yerine getirmelidir**. Bir fonksiyon çok uzayıp karmaşıklaşırsa, onu daha küçük fonksiyonlara bölmek gerekir. Bu işleme **"refactoring" (kodu yeniden yapılandırma)** denir.

---

# LearnCpp 2.7 - Forward Declarations (Ön Bildirimler) ve Definitions (Tanımlamalar)

## Derleyici Sırası ve Ortaya Çıkan Hatalar
C++ derleyicisi kodları **yukarıdan aşağıya doğru sırayla okur**. Eğer bir fonksiyonu, tanımlandığı satırlardan daha yukarıda çağırırsanız (örneğin `main` içinde), derleyici bu fonksiyonu henüz görmediği için "böyle bir fonksiyon bulunamadı" hatası verir. Bu sorunu çözmenin iki yolu vardır:
1. Fonksiyonu, çağrıldığı yerden daha yukarıda (örneğin `main`'den önce) tanımlamak (Sıralamayı düzeltmek).
2. **Forward Declaration (İleriye Dönük Bildirim / Ön Bildirim)** kullanmak.

## Forward Declaration (Ön Bildirim) Nedir?
Bir fonksiyonun gövdesini (içeriğini) yazmadan, sadece varlığını ve yapısını derleyiciye önceden bildirme işlemidir. Derleyici bu bildirimi gördüğünde, *"Bu fonksiyonun nerede olduğunu veya ne yaptığını henüz bilmiyorum ama böyle bir fonksiyon var, kontrolü buna göre yap"* diyerek hata vermez.

**Function Declaration / Function Prototype (Fonksiyon Prototipi):**
Fonksiyona ön bildirim yapmak için bu yapı kullanılır. 
* Sözdizimi: `returnType functionName(parameters);`
* **Gövde (süslü parantez `{}`) içermez**, sonuna noktalı virgül (`;`) konur.

Örnekler:
```cpp
int add(int x, int y); // Önerilen: Parametre isimleri var
int add(int, int);     // Geçerli: Sadece tipler var, isimler yok
```
*Not:* Parametre isimleri yazmak zorunlu olmasa da (derleyici tarafından yok sayılır), kodu okuyan kişinin hangi parametrenin ne işe yaradığını anlaması için isimlerin yazılması (gerçek fonksiyondaki isimlerle aynı olacak şekilde) en iyi pratiktir. Örneğin, `void doSomething(int, int, int)` tanımına bakarak hangi `int`'in ne anlama geldiğini hatırlamak zordur.

## Neden Forward Declaration Kullanırız?
* **Farklı Dosyalar:** Genellikle çağrılan fonksiyon farklı bir `.cpp` dosyasında bulunur. Bu durumda fonksiyonları yukarı taşıyarak yeniden sıralamak imkansızdır. Ön bildirim, derleyiciye "bu fonksiyon başka bir yerde var" dememizi sağlar.
* **Düzen ve Okunabilirlik:** Fonksiyonlarımızı, kodun anlaşılabilirliğini artıracak şekilde istediğimiz sırada (örneğin en üste `main`'i koyarak) yerleştirmemize olanak tanır.
* **Döngüsel Bağımlılık (Circular Dependency):** İki fonksiyon birbirini çağırıyorsa, hangisini üste koyarsanız koyun diğeri altta kalacaktır. Bu tür döngüsel durumları çözmenin tek yolu ön bildirim kullanmaktır.

*Ek Not:* Eğer bir fonksiyonun ön bildirimini yapıp programda çağırırsanız ama fonksiyonun gövdesini (tanımını) hiçbir yere yazmazsanız, **Derleyici (Compiler)** hata vermez (çünkü bildirime güvenir), ancak **Bağlayıcı (Linker)** fonksiyonun içeriğini bulamadığı için hata verir. İleriye dönük bildirimler çoğunlukla fonksiyonlar için kullanılsa da değişkenler ve türler (types) için de geçerlidir.

---

## Declarations (Bildirimler) vs. Definitions (Tanımlamalar)
C++'ta "declaration" ve "definition" terimleri genellikle birbirinin yerine kullanılsa da, teknik olarak farklıdırlar.

* **Declaration (Bildirim):** Bir tanımlayıcının varlığını derleyiciye bildirir. Gövdesi veya bellek tahsisi yoktur.
  `int add(int x, int y);` -> "add" adında bir fonksiyon olduğunu bildirir.
  
* **Definition (Tanım):** Tanımlayıcıyı fiilen uygular (fonksiyonlar için gövdesini yazar) veya somutlaştırır (değişkenler için bellekte yer ayırır).
  ```cpp
  int add(int x, int y) { return x + y; } // Fonksiyon tanımı
  int x; // Değişken tanımı (bellekte yer ayrıldı)
  ```

**Altın Kural:** *C++'ta tüm tanımlamalar (definition) aynı zamanda bir bildirimdir (declaration). Ancak tüm bildirimler tanım değildir.* Tanım içermeyen bildirimlere **"Pure Declarations" (Saf Bildirimler)** denir (Örn: Forward declarations).

Derleyicinin kodun doğru kullanıldığını doğrulaması için genellikle sadece bildirim yeterlidir. `add(5, 6)` çağrısını gören derleyici, öncesinde `add(int, int)` bildirimini gördüyse hata vermez; tanımı o an görmesine gerek yoktur. 

### Özet Tablosu

| Terim (Term) | Teknik Anlamı (Technical Meaning) | Örnekler (Examples) |
| :--- | :--- | :--- |
| **Declaration** (Bildirim) | Derleyiciye bir tanımlayıcı (identifier) ve onunla ilişkili tür bilgisi hakkında bilgi verir. | `void foo();` (ön bildirim, gövde yok)<br>`void goo() {}` (tanım, gövde var)<br>`int x;` (değişken tanımı) |
| **Definition** (Tanım) | Bir fonksiyonu uygular veya bir değişkeni somutlaştırır (bellekte yer ayırır). Tüm tanımlar aynı zamanda bildirimdir. | `void foo() {}` (fonksiyon tanımı)<br>`int x;` (değişken tanımı) |
| **Pure declaration** (Saf bildirim) | Tanım olmayan bildirimdir. | `void foo();` (fonksiyon ön bildirimi, gövde yok) |
| **Initialization** (İlk değer atama) | Tanımlanmış bir nesneye başlangıç değeri sağlar. | `int x { 2 };` (x'e 2 değeri atanarak başlatıldı) |

---

## The One Definition Rule (ODR - Tek Tanım Kuralı)
C++'taki en önemli kurallardan biridir ve üç bölümden oluşur:
1. Bir dosya içinde, belirli bir kapsamdaki (scope) her fonksiyon, değişken veya türün **yalnızca bir tanımı** olabilir. (ODR 1'in ihlali -> Derleyici hatası)
2. Tüm program (tüm dosyalar dahil) içinde, belirli bir kapsamdaki her fonksiyon veya değişkenin **yalnızca tek bir tanımı** olabilir. (ODR 2'nin ihlali -> Bağlayıcı/Linker hatası)
3. Türler, şablonlar (templates) ve inline fonksiyon/değişkenler, tanımları birbiriyle *birebir aynı olduğu sürece* farklı dosyalarda tekrarlanabilir. (ODR 3'ün ihlali -> Tanımlanmamış davranış / Undefined behavior)

---

# Günün Değerlendirme Soruları ve Cevaplarım

**Soru 1 (Mimari - 2.6):** Bir programı tek bir devasa `main` fonksiyonu yerine küçük ve bağımsız fonksiyonlara bölmenin (functional separation), kodun ilerideki bakımı ve yönetilebilirliği açısından sana sağladığı en temel mühendislik avantajı sence nedir?
* **Cevabım:** Küçük parçalara ayırıp kontrol etmesi koca bir parçayı kontrol etmekten daha kolaydır ve daha az karmaşıktır. Ayrıca soyutlama (abstraction) sağlayarak fonksiyonun iç işleyişini gizler ve kod tekrarını azaltarak projenin bakımını (maintenance) çok daha yönetilebilir hale getirir.

**Soru 2 (Derleyici Mantığı - 2.7):** C++ derleyicisi bir `.cpp` dosyasını yukarıdan aşağıya doğru okur. Sen `main` fonksiyonunun içinde, dosyada `main`'den sonra yazılmış bir `topla()` fonksiyonunu çağırdığında derleyici neden hata verir? Derleyicinin o anda neyi bilmeye ihtiyacı vardır?
* **Cevabım:** Çünkü derleyici yukarıdan aşağıya doğru okur ve `topla();` kısmına geldiğinde böyle bir fonksiyon daha oluşturulmamışsa bulamadığı için yukarıda hata verecektir. Bunun için önce ön bildirim gerekir (declaration), yani o da `int topla(int x, int y);` stilinde olmalıdır.

**Soru 3 (Mekanizma - 2.7):** İkinci sorudaki derleme hatasını çözmek için `main`'in üstüne yazdığımız "forward declaration" (örn: `int topla(int x, int y);`) derleyiciye tam olarak hangi garantiyi verir? Bir fonksiyonun "bildirimi" (declaration) ile "tanımı" (definition) arasındaki temel fark nedir?
* **Cevabım:** Böyle bir fonksiyonun varlığını (adını, dönüş türünü ve parametrelerini) derleyiciye haber eder. Derleyici de bu bildirim sayesinde fonksiyon çağrıldığında tip güvenliği (type checking) kontrolü yapabilir ve doğru argümanların girildiğinden emin olur. Her tanım bir bildiridir ama her bildiri tanım değildir. Mesela int topla(int, int); bir bildiridir ama tanım değildir. İleriye dönük bildiriler (forward declarations) tanım değildir.
---

# LearnCpp 2.7 - Quiz (Çeviri ve Düzeltmeler)

**Soru 1:** Fonksiyon prototipi (function prototype) nedir?
**Cevap:** Fonksiyon prototipi, bir fonksiyonun adını, dönüş türünü (return type), parametre türlerini ve isteğe bağlı olarak parametre adlarını içeren bir bildirim (declaration) ifadesidir. Fonksiyonun gövdesini (body) içermez. Derleyiciye, fonksiyon tanımlanmadan önce var olduğunu bildirir.

**Soru 2:** Forward declaration (Ön bildirim) nedir?
**Cevap:** İleriye dönük bir bildirim, derleyiciye bir tanımlayıcının (identifier) fiilen tanımlanmadan önce var olduğunu söyler.

**Soru 3:** Fonksiyonlar için ileriye dönük bildirimi (forward declaration) nasıl yaparız?
**Cevap:** Fonksiyonlar için, bir fonksiyon bildirimi/prototipi (function declaration/prototype) ileriye dönük bildirim görevi görür.

**Soru 4:** Aşağıdaki fonksiyon için bildirim (declaration) yazın (isimlerin belirtildiği tercih edilen formatı kullanın):

```cpp
int doMath(int first, int second, int third, int fourth)
{
     return first + second * third / fourth;
}
```
**Cevap:** Bunlar birer ifade (statement) olduğu için sonuna noktalı virgül eklemeyi unutmayın:
`int doMath(int first, int second, int third, int fourth);`

**Soru 5:** Aşağıdaki programların her biri için; derleme hatası mı vereceğini, bağlayıcı (linker) hatası mı vereceğini yoksa başarılı bir şekilde derlenip bağlanacağını belirtin.

**a)**
```cpp
#include <iostream>
int add(int x, int y);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
```
**Cevap:** Derlenmez. Derleyici, 3 argüman alan ve eşleşen bir `add()` fonksiyonu bulamadığından şikayet edecektir. `add()` fonksiyonunun ön bildiriminde yalnızca iki parametre vardır ve 3 parametreli bir `add()` fonksiyon tanımı ortada yoktur.

**b)**
```cpp
#include <iostream>
int add(int x, int y);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```
**Cevap:** Derlenmez. İlk (a) şıkkındakiyle aynı sebepten ötürü. Ön bildirim (2 parametre) ile fonksiyon çağrısı (3 parametre) uyuşmuyor.

**c)**
```cpp
#include <iostream>
int add(int x, int y);

int main()
{
    std::cout << "3 + 4 = " << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```
**Cevap:** Link (Bağlayıcı) hatası verir. Derleyici `main()` içindeki `add(3, 4)` çağrısını, yukarıdaki ön bildirimle eşleştirir ve derlemede sorun çıkarmaz. Ancak, iki parametre alan `add()` fonksiyonunun gövdesi (tanımı) hiçbir zaman yazılmamıştır (sadece 3 parametreli olan tanımlanmış). Bu yüzden linker, 2 parametreli fonksiyonun içeriğini bulamadığı için hata verecektir.

**d)**
```cpp
#include <iostream>
int add(int x, int y, int z);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int z, int y, int x) // isimler bildirimdekilerle eşleşmiyor
{
    return x + y + z;
}
```
**Cevap:** Başarıyla derlenir ve bağlanır. `add()` fonksiyon çağrısındaki argüman sayı/tipleri ön bildirimle eşleşir. Fonksiyon tanımı (definition) da parametre sayısı ve tipi olarak eşleşmektedir. İsimlerin bildirimdekiyle eşleşmemesi önemli değildir çünkü bildirimdeki (declaration) isimler isteğe bağlıdır ve derleyici tarafından göz ardı edilir.

**e)**
```cpp
#include <iostream>
int add(int, int, int); // parametre isimleri yok

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```
**Cevap:** Başarıyla derlenir ve bağlanır. Bu, d şıkkındaki durumla aynı mantıktadır. Fonksiyon bildirimlerinde parametrelerin isimlerini belirtmek zorunlu değildir (yine de genelde dahil etmeyi tercih etsek de).

**f)**
```cpp
#include <iostream>

int add(int x, int y);

int add(int x, int y, int z)
{
    return x + y + z;
}

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}
```
**Cevap:** Başarıyla derlenir ve bağlanır. İki parametreli `add()` fonksiyonunun ön bildirimi yapılmıştır, ancak programın hiçbir yerinde kullanılmadığı için sorun çıkarmaz (derleyici tarafından göz ardı edilir). `main` içerisindeki 3 argümanlı çağrı, hemen üstündeki 3 parametreli tanım ile eşleşerek hatasız çalışır.
