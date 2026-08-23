# LearnCpp Chapter 1 Özet (Review) ve Sorular

## Temel Kavramlar ve Tanımlar

*   **Statement (Deyim/İfade):** Programın belirli bir eylemi gerçekleştirmesini sağlayan bir komut türüdür. Genellikle noktalı virgülle (`;`) biterler.
*   **Function (Fonksiyon/İşlev):** Statement'ların sırayla yukarıdan aşağıya doğru yürütüldüğü bütündür. Her C++ programı özel bir `main` adındaki fonksiyonu barındırmak zorundadır. Program başlayınca `main` fonksiyonundan aşağıya doğru okur.
*   **Identifier (Tanımlayıcı):** Bir fonksiyonun (veya nesnenin, türün, şablonun vb.) adına “tanımlayıcı/identifier” denir.
*   **Syntax (Sözdizimi):** C++ dilindeki öğelerin nasıl oluşturulduğunu belirleyen kurallara sözdizimi denir. Dilin gramer kurallarına uymadığınızda sözdizimi hatası (syntax error) oluşur. Konuşma dillerindeki gramer kuralları gibidir.
*   **Comments (Yorumlar):** Programcının kodda notlar bırakmasına olanak tanır. C++, iki tür yorumu destekler. Satır yorumları `//` ile başlar ve satırın sonuna kadar uzanır. Blok yorumları `/*` ile başlar ve eşleşen `*/` sembolüne kadar uzanır. Blok yorumlarını iç içe yerleştiremeyiz.
*   **Commenting Out (Yorum Satırına Almak):** Yorumları, kod satırlarını veya bölümlerini geçici olarak devre dışı bırakmak için kullanabilirsiniz.
*   **Data (Veri):** Bir bilgisayar tarafından taşınabilen, işlenebilen veya depolanabilen herhangi bir bilgidir.
*   **Value (Değer):** Tek bir veri birimine değer denir. Değerlere yaygın örnekler arasında harfler/karakterler (örn. 'a'), sayılar (örn. 5) ve metinler (örn. "Merhaba") bulunur.
*   **Variable (Değişken):** Değerleri depolamak için kullanabileceğimiz, adı belirlenmiş bir bellek parçasıdır. Bir değişken oluşturmak için “tanım deyimi/definition statement” adı verilen bir deyim kullanırız. Program çalıştırıldığında, tanımlanan her değişkenin bir örneği oluşturulur (instantiated); bu, ona bir bellek adresi atandığı anlamına gelir.
*   **Data Type (Veri Türü):** Derleyiciye bir veriyi anlamlı bir değere nasıl dönüştüreceğini belirtir. Tamsayı (integer), 4, 27, 0, -2 veya -12 gibi kesirli kısmı olmayan sayılardır.
*   **Copy Assignment (Kopya Ataması):** (`operator=` operatörü aracılığıyla), önceden oluşturulmuş bir değişkene bir değer atamak için kullanılabilir.
*   **Initialization (Başlatma):** Bir nesneye başlangıç değeri belirleme işlemidir.
*   **Initializer (Başlatıcı):** Bir nesneyi başlatmak için kullanılan sözdizimidir.

## Başlatma (Initialization) Türleri

| Başlatma Türü (İngilizce) | Başlatma Türü (Türkçe) | Örnek | Not |
| :--- | :--- | :--- | :--- |
| Default-initialization | Varsayılan Başlatma | `int x;` | Çoğu durumda, değişkenin değeri belirsiz (çöp değer) kalır. |
| Copy-initialization | Kopyalama yoluyla başlatma | `int x = 5;` | |
| Direct-initialization | Doğrudan başlatma | `int x ( 5 );` | |
| Direct-list-initialization | Doğrudan liste başlatma | `int x { 5 };` | Daraltma (narrowing) dönüşümlerine izin verilmez. |
| Copy-list-initialization | Kopyalama liste başlatma | `int x = { 5 };` | Daraltma dönüşümlerine izin verilmez. |
| Value-initialization | Değer başlatma | `int x {};` | Genellikle sıfırla başlatma (zero-initialization) gerçekleştirir. |

*   Doğrudan başlatma bazen **parenthesis-initialization** (parantez başlatma) olarak adlandırılır.
*   Liste başlatma (değer başlatma dahil) ise bazen **uniform-initialization** (tekdüze başlatma) veya **brace-initialization** (köşeli parantez başlatma) olarak adlandırılır.
*   *En iyi pratik:* Diğer başlatma biçimlerine kıyasla köşeli parantez (brace) başlatmayı tercih etmelisiniz; atamaya kıyasla da başlatmayı tercih etmelisiniz.
*   Tek bir ifadede birden fazla değişken tanımlayabilseniz de, her bir değişkeni ayrı bir satırda, ayrı bir ifadeyle tanımlamak ve başlatmak daha iyidir.

## Giriş/Çıkış ve Diğer Kavramlar

*   **`std::cout` ve `operator<<`:** Bir ifadenin sonucunu konsola yazdırmamızı sağlar.
*   **`std::endl`:** Satır sonu karakteri yazdırarak konsol imlecinin bir sonraki satıra geçmesini sağlar ve konsola gönderilmeyi bekleyen tüm çıktıları anında gönderir (flush).
*   **`'
'` (Newline Character):** Satır sonu karakteri yazdırır, ancak çıktının ne zaman gönderileceğine (flush edileceğine) sistemin karar vermesine izin verir. `/n` (eğik çizgi) kullanmamaya dikkat edin.
*   **`std::cin` ve `operator>>`:** Klavyeden bir değer almamızı sağlar.
*   **Uninitialized Variable (Başlatılmamış Değişken):** Değer atanmamış bir değişkendir. Başlatılmamış bir değişkenin değerini almaya çalışmak, **undefined behavior** (tanımlanmamış davranış) yol açar.
*   **Undefined Behavior (Tanımlanmamış Davranış):** C++ dil kurallarına göre derleyicinin ne yapacağını bilememe durumudur ve programın çökmesine veya rastgele saçma sapan sonuçlar üretmesine neden olabilir.
*   **Keywords (Anahtar Kelimeler):** C++ tarafından ayrılmış bir dizi addır. Dil içinde özel bir anlam taşır ve değişken adı olarak kullanılamazlar.
*   **Literal Constant (Sabit):** Kaynak koduna doğrudan eklenen sabit bir değerdir. (örn. 5 veya “Hello world!”).
*   **Operation (İşlem):** "İşlenenler (operands)" olarak adlandırılan sıfır veya daha fazla girdi değerini içeren bir süreçtir.
*   **Operator (İşleç):** Gerçekleştirilecek belirli işlemi belirtir. Bir işlemin sonucu bir çıktı üretir.
*   **Arity (İşlenen Sayısına Göre Operatörler):**
    *   **Unary (Tekli):** Bir işlenen (operand) alır.
    *   **Binary (İkili):** İki işlenen alır (sol ve sağ).
    *   **Ternary (Üçlü):** Üç işlenen alır.
    *   **Nullary (Sıfırlı):** Sıfır işlenen alır.
*   **Expression (İfade):** Tek bir çıktı değeri üretmek üzere değerlendirilen (evaluate edilen) sabitler, değişkenler, işleçler ve işlev çağrılarından oluşan bir dizidir.
*   **Evaluation (Değerlendirme):** Çıktı değerinin hesaplanması sürecidir.
*   **Result (Sonuç):** Üretilen değere denir.
*   **Expression Statement (İfade Deyimi):** İfadenin sonuna noktalı virgül (`;`) eklenerek deyime dönüştürülmüş halidir.

## Programlama Pratikleri

*   Program yazarken, birkaç satır veya bir işlev ekleyin, derleyin, hataları giderin ve programın çalıştığından emin olun. Programın tamamını yazana kadar beklemeyin!
*   Öncelikle kodunuzun çalışır hale gelmesine odaklanın. Çalıştığından emin olduktan sonra temizlik (gereksiz mantığı silme, yorum ekleme, formatlama) yapın. İlk taslaklar dağınıktır, mükemmellik iyileştirmeyle (refinement) gelir.

---

## Günün Soru-Cevapları (Özel Notlar)

**Soru 1 (Özel):** Kullanıcıdan sayı almak için `int sayi;` şeklinde bir değişken tanımlayıp, `std::cin >> sayi;` ile değer atamayı unutsaydık ve bu değişkeni doğrudan ekrana yazdırmaya çalışsaydık ne olurdu?
**Cevap 1:** `int sayi;` varsayılan başlatma (default initialization) yapar. Değer 0 olmaz; bellekte o adreste kalan rastgele bir "çöp değer (garbage value)" atanır. Bu durum tanımsız davranışa (undefined behavior) yol açar. Modern derleyiciler bunu fark edip (uninitialized local variable used) hatası vererek programı çökertir.

**Soru 2 (Özel):** `int x;` yerine `int x{};` yapsaydık ve `std::cin` ile değer almayı yine unutsaydık sonuç ne olurdu?
**Cevap 2:** İşte o zaman değer **0** olurdu. `int x{};` (değer başlatma), eğer içine bir şey yazılmazsa otomatik olarak sıfırla başlatma (zero-initialization) gerçekleştirir. Program hata vermez, çökelmez ve sessizce 0 üzerinden çalışmaya devam eder. C++'ta süslü parantez kullanılmasının temel sebebi, değişkenlerin rastgele çöp değerlerle sisteme zarar vermesini engellemektir.

**Soru 3 (Chapter Quiz):** `int x { 5 };` ile yapılan işleme **Başlatma (Initialization)**, daha sonra alt satırlarda `x = 10;` yapmaya ise **Atama (Assignment)** diyoruz. Bu iki kavramın arasındaki temel mantık farkı nedir ve bir değişken hayatı boyunca kaç kez "başlatılabilir", kaç kez "atanabilir"?
**Cevap 3:** Başlatma (Initialization), değişkene oluşturulduğu an (bellekte yer ayrıldığı an) ilk değerini verme işlemidir ve bir değişken hayatı boyunca sadece **bir kez** başlatılabilir. Atama (Assignment) ise halihazırda var olan bir değişkene yeni bir değer verme işlemidir ve **istediğin kadar (sınırsız)** atama yapabilirsin.

**Soru 4 (Chapter Quiz):** Kod yazarken alt satıra geçmek için `std::endl` kullanmak ile `'
'` karakterini kullanmak arasındaki teknik fark nedir? C++ neden genellikle `'
'` kullanmamızı tavsiye eder?
**Cevap 4:** `std::endl` sadece alt satıra geçmekle kalmaz, aynı zamanda çıktı tamponunu (buffer) anında temizler/boşaltır (flush). Sık kullanıldığında bu tampon temizleme işlemi sistemi yavaşlatabilir. `'
'` ise sadece alt satıra geçer ve tamponun ne zaman boşaltılacağına sistemin karar vermesini sağlar; bu nedenle çok daha performanslıdır.

**Soru 5 (Chapter Quiz):** "Tanımlanmamış davranış" (Undefined behavior) tam olarak nedir ve şu ana kadar öğrendiklerimize göre en çok hangi hatayı yaptığımızda bu durumla karşılaşırız?
**Cevap 5:** Tanımlanmamış davranış, C++ derleyicisinin yazılan kod karşısında dil kurallarına göre ne yapacağını bilememesi (kuralların dışına çıkılması) durumudur. Bu durumla şu ana kadar en çok `int x;` şeklinde başlatılmamış (uninitialized) değişkenlerin değerini okumaya veya kullanmaya çalıştığımızda karşılaşırız.
