# C++'ta Initialization ve Assignment (Bölüm 1.4)

## Temel Kavramlar

**Assignment (Atama):** Daha önceden oluşturulmuş bir değişkenin değerini `=` operatörü ile değiştirmektir. (örn: `width = 5;`)
**Initialization (İlk Değer Atama):** Bir değişkenin RAM'de oluşturulduğu ilk anda (ayrıldığı an) başlangıç değerinin verilmesidir.

### Başlatma (Initialization) Formları

1. **Default-initialization:** `int a;`
   - Başlatıcı yoktur.
   - Değer belirsizdir (garbage value). Kullanımı tehlikelidir ve Undefined Behavior (UB) sorunlarına yol açar.
2. **Copy-initialization:** `int b = 5;`
   - `=` işaretinden sonra değer verilir. Geleneksel yöntemdir.
3. **Direct-initialization:** `int c(6);`
   - Değer parantez içine yazılır.
4. **Direct-list-initialization:** `int d{7};`
   - Değer süslü parantez içine yazılır. **Modern C++'ta en çok tercih edilen yöntemdir.**
5. **Value-initialization:** `int e{};`
   - İçi boş süslü parantez kullanılır. Değişkeni güvenli bir şekilde `0` (sıfır) ile başlatır (zero-initialization). Değerin daha sonra değiştirileceği durumlarda tercih edilir.

### Neden List-Initialization (Süslü Parantez) Kullanmalıyız?
Süslü parantez ile başlatma, veri kaybına neden olan "daraltma dönüştürmelerini" (narrowing conversions) yasaklar.
- `int w2 = 4.5;` yazıldığında derleyici .5 kısmını atıp değeri 4 olarak kaydeder (veri kaybı yaşanır).
- `int w1{4.5};` yazıldığında ise liste yöntemi daraltmayı yasakladığı için derleyici doğrudan hata verir. Bu, olası mantık hatalarını kod yazım aşamasında yakalamamızı sağlar.

### Birden Fazla Değişkeni Başlatma Riskleri
`int a, b = 5;` kodu hatalıdır. Burada yalnızca `b` değişkeni 5 ile başlatılır, `a` değişkeni başlatılmamış (uninitialized) olarak kalır. Bu durum programın rastgele çökmesine yol açabilir. Doğrusu `int a = 5, b = 5;` şeklindedir.

### `[[maybe_unused]]` Özniteliği (C++17)
Modern derleyiciler tanımlanıp kullanılmayan değişkenler için hata/uyarı üretir. Bazen sabit değerler kütüphanesinden kopyaladığımız değişkenlerin hepsini o programda kullanmayabiliriz. Değişkenin başına `[[maybe_unused]] double gravity { 9.8 };` yazarak derleyiciye bu durumun kasıtlı olduğunu bildirir ve hata almayı engelleriz.

### `return 0;` Kullanımı
`main` fonksiyonu, sonuna `return 0;` yazılmasa bile derleyici tarafından arka planda otomatik olarak 0 döndürecek şekilde ayarlanmıştır. Ancak; işletim sistemine "hiçbir sorun çıkmadı" mesajını vermek ve diğer fonksiyonlarda return kullanma alışkanlığını kaybetmemek adına kodu `return 0;` ile bitirmek en doğru mühendislik pratiğidir.

---

## Soru - Cevap (Active Recall)

**Soru 1:** Initialization ile assignment arasındaki fark nedir?
**Cevap:** Initialization, değişken oluşturulduğu anda ona ilk değerini verir. Assignment ise değişken oluşturulduktan sonraki bir noktada (sonradan) değerini değiştirir.

**Soru 2:** Bir değişkeni belirli bir değerle başlatmak istediğinizde hangi başlatma formunu tercih etmelisiniz?
**Cevap:** Direct-list-initialization (Doğrudan liste başlatma / süslü parantez ile başlatma).

**Soru 3:** Default-initialization ve value-initialization nedir? Her birinin davranışı nedir? Hangisini tercih etmelisiniz?
**Cevap:** Default-initialization başlatıcı olmadığında gerçekleşir (örn. `int x;`) ve değişken belirsiz (çöp) bir değerde kalır. Value-initialization boş süslü parantez olduğunda gerçekleşir (örn. `int x{};`) ve değişkeni sıfırla başlatır (zero-initialization). Tutarlı bir değer verdiği için her zaman value-initialization tercih edilmelidir.

**Soru 4:** `int x{ 5 }, y = 6;` kodu hata vermeden çalışmasına rağmen mühendislik açısından neden kullanılması tavsiye edilmez? Eğer bu kodu `int x{ 5.5 }, y = 6.5;` şeklinde değiştirseydik derleyici nasıl tepki verirdi?
**Cevap:** Bu kod iki sebeple tavsiye edilmez: 
1. Tutarsızlık: Aynı satırda hem modern (`{}`) hem geleneksel (`=`) başlatma yöntemleri bir arada kullanılarak kodun standartları bozulmuştur. 
2. Hata Riski: Aynı satırda çoklu değişken tanımlamak, anlık bir dalgınlıkla (örn: `int x, y = 6;`) değişkenlerden birinin başlatılmasını unutmaya ve Undefined Behavior (UB) sorunlarına zemin hazırlar. En doğru kullanım her değişkeni ayrı satırda süslü parantez ile başlatmaktır. 

Ondalıklı bir değer denediğimizde ise; `x` değişkeni süslü parantez `{}` ile tanımlandığı için daraltma (narrowing conversion) işlemi yasaklanmıştır ve derleyici anında hata verir. Ancak `y` değişkeni `=` ile tanımlandığı için daraltmaya izin verir ve küsuratı atarak değişkeni gizlice 6 olarak kaydeder (veri kaybı yaşanır).