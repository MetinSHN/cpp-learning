# LearnCpp - Chapter 1.3: Değişkenler (Variables) ve Veri Tipleri

## 1. Veri (Data) ve Kod (Code) Kavramları
* **Data (Veri):** Bir bilgisayar tarafından taşınabilen, işlenebilen veya depolanabilen her türlü bilgidir. Programların gerçek bir sonuç üretmesini sağlayan ana unsurdur.
* **Code (Kod):** Bilgisayar programlarının ta kendisidir. Programlar da aslında birer veridir (depolanabilir, taşınabilir); ancak programın *kendisine* "kod", çalışırken işlediği bilgilere ise "veri" denir.

Bir program verileri; bir dosyadan, veritabanından, ağ üzerinden, klavyeden (kullanıcı girdisi) veya doğrudan kaynak kodun içinden (programcı tarafından) alabilir.

### Veri Değerleri (Values)
Programlamada tek bir veri parçasına "value" (değer) denir. Örnekler:
* Sayılar: `0`, `1`, `-6.7` (Tırnak içine alınmazlar)
* Karakterler: `'H'`, `'$'` (Tek tırnak içine alınırlar, tek bir sembolden oluşurlar)
* Metinler (Text): `"Hello"`, `"H"` (Çift tırnak içine alınırlar, derleyici tarafından metin olarak yorumlanırlar)

## 2. Sabit Değerler (Literals)

Kaynak kodun içine doğrudan, ham olarak yazılan ve değiştirilemeyen sabit değerlere **literal** denir. 

*   **Analoji (Kutu-Nesne İlişkisi):** Kod yazarken değişkenler içini değiştirebildiğimiz birer **kargo kutusu** ise, literaller bu kutuların içine koyduğumuz **fiziksel nesnelerin (ham maddenin)** kendisidir.

### Temel Özellikleri, Avantaj ve Dezavantajları
*   **Avantajı:** Programa veri sağlamanın en kolay ve hızlı yoludur. Derleyici, bu değerleri doğrudan işlemci komutlarının (makine kodunun) içine gömer.
*   **Dezavantajı (Salt Okunurluk):** Literaller **salt okunur (read-only)** değerlerdir. Program çalışırken hafızada dinamik olarak değiştirilemezler. Sürekli değişen veya dışarıdan alınan verileri (örneğin kullanıcının girdiği bir şifreyi veya ismi) saklamak için doğrudan kullanılamazlar.
*   **İsimsiz Olmaları:** Değişkenlerin aksine (`yas`, `sayac` gibi) kendilerine ait bir isimleri yoktur, sadece kendi değerleriyle var olurlar.

### Değişken ve Literal Ayrımı (Kod Üzerinde)

```cpp
int x = 10;
x = 20;
std::cout << 50;
```
*   Yukarıdaki kodda `x` bir **değişken** (kutu) iken; `10`, `20` ve `50` değerleri kodun neresinde olursa olsun birer **literaldir**. `x`'in değeri program akışında değişebilir ancak `10` veya `20` sayılarının kendileri asla değiştirilemez (`10 = 30;` gibi bir kullanım hatalıdır).

### ⚠️ Kritik Detay: Atama (`=`) Operatörünün Sağ Tarafı Her Zaman Literal midir?
Bir değerin literal olması için `=` operatörünün sağında yer alması **şart değildir** (Yukarıdaki `std::cout << 50;` örneğinde olduğu gibi). Ayrıca `=` operatörünün sağındaki her ifade de literal olmak zorunda değildir:

1.  **Sağı Literal Olan:** `int y = 30;` (Doğrudan ham veri yazılmıştır -> `30` literaldir).
2.  **Sağı Değişken Olan:** `int z = y;` (Sağ tarafta ham bir veri değil, başka bir değişken adı vardır -> Literal değildir).
3.  **Sağı İşlem (İfade) Olan:** `int toplam = 10 + 20;` (Sağ taraf bir matematiksel ifadedir. İfadenin bütünü literal değildir ancak içindeki `10` ve `20` sayıları birer literaldir).


## 3. RAM (Random Access Memory)
Programı çalıştırdığımızda işletim sistemi programı RAM'e (Rastgele Erişim Belleği) yükler. 
* Sabit kodlanmış veriler (literaller) bu aşamada RAM'e alınır.
* İşletim sistemi, program çalışırken (run-time) dinamik olarak kullanılmak üzere ek bir RAM alanı daha ayırır.
* RAM'i, içine verilerin konulabildiği "numaralandırılmış milyonlarca boş kutu" gibi düşünebilirsiniz.

## 4. Nesneler (Objects) ve Değişkenler (Variables)
C++'ta bellek (RAM) ile etkileşime geçmek için nesneleri ve değişkenleri kullanırız.

* **Object (Nesne):** RAM'de veya CPU kaydında, içinde bir değer barındırabilen depolama alanıdır (kutunun kendisi).
* **Variable (Değişken):** Kendisine bir **isim (tanımlayıcı)** verilmiş olan nesnelerdir. 

*Not: Her değişken bir nesnedir, ancak her nesne bir değişken değildir (nesneler isimsiz/anonim olabilir).*

## 5. Tanımlama (Definition) ve Tahsis Etme (Allocation)
Bir değişkeni kullanabilmek için önce onu derleyiciye tanıtmamız (define) gerekir.

```cpp
int x; // x adında, integer (tamsayı) türünde bir değişken tanımlar.
```

### Aşama 1: Derleme Zamanı (Compile-time)
Derleyici `int x;` satırını gördüğünde bunun bir tamsayı olduğunu kaydeder. Ne kadar belleğe ihtiyaç duyulacağını, bellekteki konumlandırma kurallarını ve ömrünü planlar.

### Aşama 2: Çalışma Zamanı (Run-time / Allocation)
Program belleğe yüklenip çalıştırıldığında, bu değişken için RAM'de gerçekten fiziksel bir yer (depolama alanı) ayrılır. Belleğin bu şekilde nesnenin kullanımına sunulması işlemine **Allocation (Tahsis)** denir.

## 6. Veri Türleri (Data Types)
* **Integer (int):** `4`, `0`, `-12` gibi kesir kısmı olmayan tamsayılardır.

C++'ta bir değişkenin veri türü **derleme sırasında** bilinmek zorundadır. Derleyici, o türün RAM'de ne kadar yer kaplayacağını bu sayede anlar. Bir kez `int` olarak tanımlanan değişkene, program çalıştığı sürece yalnızca tamsayı atanabilir (türü sonradan değiştirilemez).

### Çoklu Değişken Tanımlama Hataları
Aynı türdeki birden fazla değişken virgül kullanılarak tek satırda tanımlanabilir:
```cpp
int a, b; // Doğru: Hem a hem de b birer int'tir.
```

**Yaygın Hatalar:**
1. *Aynı satırda türü tekrar yazmak:* 
   `int a, int b;` (Hatalıdır, virgülle ayrılmış listede tür sadece en başa yazılır)
2. *Aynı satırda farklı türler tanımlamaya çalışmak:*
   `int a, double b;` (Hatalıdır, C++ kurallarına göre aynı ifade içinde farklı türler virgülle bağlanamaz. Ayrı satırlara yazılmalıdır.)

```cpp
// En doğru ve tavsiye edilen kullanım:
int a;
double b;
```

---

## Öğrenme Kontrolü (Active Recall Soru & Cevapları)

**Soru 1: Literaller programa veri sağlamanın en kolay yolu olmasına rağmen, neden bütün verileri literaller olarak bırakamıyoruz?**
* **Cevabım:** Bu değerler salt okunurdur, bu yüzden değerleri değişmez. Değişen verileri takip edemeyeceğimiz için yalnızca literalleri kullanamayız.
* **Değerlendirme:** Kesinlikle doğru. Literal "sabit" demektir. Kullanıcıdan alınacak bir yaşı veya bir oyundaki skoru literallerle tutamayız, çünkü bu veriler program çalışırken sürekli değişir.

**Soru 2: Her değişken aslında bir nesnedir (object) ama her nesne bir değişken değildir. Bir nesneyi "değişken" yapan o kritik özellik nedir?**
* **Cevabım:** İsmi olan (tanımlanan) nesnelere değişken deriz.
* **Değerlendirme:** Tam isabet. Değişken (variable) = İsimlendirilmiş Nesne (named object).

**Soru 3: Derleyici `int x;` satırını okuduğunda (derleme aşamasında) ne yapar, program çalıştırıldığında (allocation) ne olur?**
* **Cevabım:** Derleyici bu `x`'in integer olduğunu kaydeder, ne kadar belleğe ihtiyaç duyulacağını vb. halleder. Allocation'da ise depolamak için konum (alan) ayırır.
* **Değerlendirme:** Çok başarılı bir anlatım. Derleme aşaması işin "planlama ve mimari" kısmıdır. Allocation ise program çalışırken şantiyede (RAM'de) "arazinin fiziksel olarak çevrilmesi" kısmıdır.

**Soru 4: Neden `int a, double b;` yazmak C++ kurallarına aykırıdır?**
* **Cevabım:** `,` kullanıyoruz bu "ve" anlamına geliyor. `double` dediğimiz şeyi de aslında integer olarak tanımlıyoruz lakin boşluk `b` yazınca syntax hatası veriyor, gramere uymuyor.
* **Değerlendirme (Düzeltme):** Mantık yürütmen doğru yönde. C++'ta satır başındaki `int` kelimesi, o ifadedeki (noktalı virgüle kadar olan) tüm isimlerin `int` olacağını derleyiciye bildirir. Derleyici `int a, ` kısmını okuduktan sonra senden sadece bir "isim" bekler. Ancak sen oraya `double` kelimesini (başka bir türü) yazdığında derleyicinin kafası karışır. Farklı veri türleri için her zaman yeni bir ifade (yeni bir satır) başlatmak zorundayız.