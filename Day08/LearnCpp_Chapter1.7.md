# LearnCpp Bölüm 1.7: Keywords and Naming Identifiers

## 1. Keywords (Anahtar Kelimeler)
C++'ın kendi iç işleyişi için ayırdığı, özel anlamı olan 92 kelimelik bir kümedir. Bu kelimeler değişken veya fonksiyon adı olarak **kullanılamaz**. IDE'ler bu kelimeleri otomatik olarak renklendirerek ayırt etmeni sağlar.

alignas alignof and and_eq
asm auto bitand bitor
bool break case catch
char char8_t char16_t char32_t
class compl concept const
consteval constexpr constinit const_cast
continue co_await co_return co_yield
decltype default delete do
double dynamic_cast else enum
explicit export extern false
float for friend goto
if inline int long
mutable namespace new noexcept
not not_eq nullptr operator
or or_eq private protected
public register reinterpret_cast requires
return short signed sizeof
static static_assert static_cast struct
switch template this thread_local
throw true try typedef
typeid typename union unsigned
using virtual void volatile
wchar_t while xor xor_eq

> **Not:** `char8_t`, `concept`, `consteval`, `constinit`, `co_await`, `co_return`, `co_yield`, `requires` gibi işaretli olanlar **C++20** ile dile eklenmiştir. C++20'den düşük bir derleyici sürümü kullanıyorsan, derleyicin bu kelimeleri keyword olarak görmeyecektir.
> **Özel Tanımlayıcılar:** C++ ayrıca `override`, `final`, `import` ve `module` gibi özel kelimelere sahiptir. Bunlar sadece belirli bağlamlarda özel anlam taşır, her yerde ayrılmış (rezerve) değillerdir.

---

## 2. Identifier Naming Rules (Katı Kurallar)
Bir değişken, fonksiyon vb. isimlendirilirken (identifier) C++ derleyicisinin **kesinlikle** hata vereceği (Invalid) ve asla esnetilmeyen kurallar:

1. **Keyword Olamaz:** C++'ın ayırdığı özel kelimeler (örn: `void`, `int`, `return`) isim olarak kullanılamaz.
2. **Karakter Kısıtlaması:** Sadece büyük/küçük harfler, rakamlar ve alt çizgi (`_`) içerebilir. Boşluk ( ), soru işareti (`?`), nokta (`.`) gibi semboller **kullanılamaz**.
3. **Başlangıç Karakteri:** Kesinlikle bir harf veya alt çizgi (`_`) ile başlamalıdır. **Rakamla başlayamaz**.
4. **Büyük/Küçük Harf Duyarlılığı (Case-Sensitive):** C++ büyük/küçük harf ayrımı yapar. `uvalue` ve `Uvalue` tamamen farklı iki değişkendir.

---

## 3. Identifier Naming Best Practices (Sektör Standartları ve Gelenekler)
Derleyicinin hata vermediği (kodu çalıştırdığı) ama yazılım dünyasında "doğru" kabul edilen isimlendirme gelenekleri (Conventions).

**Kural 1: Harf Kullanımı ve Biçim**
* Değişkenler ve fonksiyonlar her zaman **küçük harfle** başlamalıdır (Örn: `main` fonksiyonu).
* Tek kelimelik isimler tamamen küçük harf olmalıdır.
* Birden çok kelime içeriyorsa iki standarttan biri tercih edilmelidir:
  * `snake_case` (Kelimeler alt çizgi ile ayrılır)
  * `camelCase` (İlk kelime küçük, sonrakilerin ilk harfi büyük)

**Kural 2: Alt Çizgi (`_`) ile Başlamamak**
* Değişken isimlerini alt çizgi ile başlatmak derleyici açısından yasak değildir ancak **tavsiye edilmez**. İşletim sistemleri, kütüphaneler ve derleyiciler kendi iç isimlendirmeleri için alt çizgi ile başlayan isimleri rezerve ederler. Çakışma olmaması için kendi kodumuzda bundan kaçınmalıyız.

**Kural 3: Açıklayıcılık ve Uzunluk Orantısı**
* Değişken adı, kodun ne yaptığını hiç bilmeyen birine bile amacını hemen anlatabilmelidir.
* **Kapsam (Scope) Kuralı:** İsim uzunluğu, o değişkenin ne kadar geniş bir alanda kullanıldığına orantılı olmalıdır.
  * Sadece 2-3 satırlık çok kısa bir işlemde kullanılan önemsiz bir değişken (`i`, `x1` gibi) kısa kalabilir.
  * Programın birçok yerinden erişilen veya çok spesifik bir değeri tutan (örn: `minutesElapsed`) değişkenlerin ismi daha uzun ve net olmalıdır.
* Yaygın ve anlamı net olanlar (örn: `max`, `min`) dışında, anlaşılmaz kısaltmalardan (örn: `ccount`) kaçınılmalıdır.

---

## 4. İsimlendirme Örnekleri (Kategorize Edilmiş)

### A. Conventional (Kurallara ve Geleneklere Uygun / İyi Kullanım)
* `int sum {};` (Ne toplandığı belli bağlamlarda uygundur)
* `int numFruit {};` (camelCase, açıklayıcı)
* `int meters_of_pipe {};` (snake_case, açıklayıcı)
* `int customerCount {};` (Ne saydığımız net belli)
* `int numApples {};` (Açıklayıcı)
* `int monstersKilled {};` (Açıklayıcı)

### B. Unconventional (Derleyici Kabul Eder Ama Tavsiye Edilmez / Kötü Kullanım)
* `int _apples {};` (Değişkenler alt çizgi ile başlamamalıdır)
* `int VALUE {};` (Tek kelime, tamamen küçük harf olmalıdır)
* `int TotalCustomers {};` (Değişkenler küçük harfle başlamalıdır -> `totalCustomers` olmalı)

### C. Invalid (Derleyici Hata Verir / Geçersiz Kullanım)
* `int my variable name {};` (Boşluk kullanılamaz)
* `int void {};` (`void` bir C++ keyword'üdür, kullanılamaz)
* `int 3some {};` (Değişken ismi rakamla başlayamaz)

### D. Bağlama Göre Değişen Kullanımlar (İyi / Kötü Olabilir)
* `int i {};` / `int x1, x2 {};` (Kullanımı çok basit/kısa bir döngüdeyse uygun, genelde kötü)
* `int index {};` (Neyi indekslediğimiz o bağlamda çok barizse uygun)
* `int totalScore {};` (Skoru tutulan sadece tek bir şey varsa uygun, birden fazla oyuncu/durum varsa yetersiz)
* `int count {};` (Neyi saydığımız barizse uygun, yoksa belirsiz)
* `int minutesElapsed {};` (Neyin üzerinden geçen dakika olduğu belli bir bağlamdaysa uygundur)

### E. Kesinlikle Kötü (Anlamı Belirsiz)
* `int ccount {};` ('c' harfinin neyi kısalttığı belli değil)
* `int data {};` (Ne verisi? Çok belirsiz)
* `int time {};` (Saniye mi, dakika mı, saat mi olduğu belirsiz)
* `int userinput1, userinput2 {};` (İsim çok uzun ve bitişik olduğu için birbirinden ayırması zor)

---

## 5. Active Recall (Öğrenme Kontrolü)

**Soru 1: C++'ta bir tanımlayıcının (identifier) derleyiciden geçebilmesi için kesinlikle uyması gereken 3 temel kural nedir?**
**Cevap:** 1. Keywords kullanılamaz. 2. Boşluk (ve semboller) bulunamaz. 3. İsim rakamla başlayamaz.

**Soru 2: Bir değişkenin adını alt çizgi (_) ile başlatmak derleyici açısından yasak mıdır? Yasak değilse neden bu kullanımdan kaçınmamız tavsiye ediliyor?**
**Cevap:** Yasak değildir ama kütüphaneler, işletim sistemleri ve derleyiciler kendi altyapılarında kullandığı için çakışma olmaması adına tavsiye edilmez.

**Soru 3: `int TotalCustomers {};` ve `int VALUE {};` tanımlamaları neden "unconventional" kabul edilir? En doğru yazım şekilleri nasıl olmalıdır?**
**Cevap:** C++'ta değişkenlerin isimleri küçük harfle başlamalı ve (tek kelime ise) küçük harfle devam etmelidir. `TotalCustomers` yerine `totalCustomers`, `VALUE` yerine `value` kullanılması daha doğru bir adlandırma olacaktır.

**Soru 4: İsimlendirme uzunluğunu belirlerken uyguladığımız kural nedir?**
**Cevap:** Değişkenin kapsamına (scope) bağlıdır. Örneğin başka yerlerden (veya geniş bir kapsamdan) ulaşılabilir bir değişkense ne işe yaradığını anlatması için uzun/açıklayıcı olması daha iyidir. Sadece birkaç satırda kalacaksa kısa olabilir.