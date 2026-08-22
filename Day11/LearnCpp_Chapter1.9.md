# C++ Temelleri: Literals, Operators, Return Values ve Side Effects

## 1. Literals (Sabitler) ve Değişkenler Arasındaki Fark

**Literals:**
```cpp
std::cout << "Hello World!";
int x {5};
```
Buradaki `"Hello World!"` ve `5` sabitlerdir (literals). Sabit değer, kaynak koduna doğrudan eklenmiş değişmez bir değerdir. Sabitlerin de değişkenlerin de birer değeri vardır ama değişkenlerin aksine sabitlerin değeri asla değişmez. `5` sabitinin değeri her zaman 5'tir. Bu değerler genellikle yürütülebilir kodda doğrudan yer alır (optimizasyon sırasında kaldırılmadıkları sürece).

**Değişkenler (Variables/Objects):**
Nesneler ve değişkenler, değerleri barındıran bellek konumlarını temsil eder. Bu değerler ihtiyaç duyulduğunda bellekten alınabilir. Değişkenlerin değeri program çalışırken değiştirilebilir.

```cpp
#include <iostream>

int main()
{
    std::cout << 5 << '\n'; // Literalin (sabitin) doğrudan kendisini yazdırdık.

    int x { 5 };
    std::cout << x << '\n'; // Değişkenin değerini yazdırdık (bellekten çekilir).
    return 0;
}
```
*Not: İkisinde de ekrana 5 yazılıyor ama birinde doğrudan sabit değer kullanılırken, diğerinde değişkenin bellekten değeri çekiliyor.*

---

## 2. Operators (Operatörler) ve Operands (İşlenenler)

Matematikte işlem (operation), sıfır veya daha fazla girdi değeri (bunlara **operand / işlenen** denir) alan ve yeni bir değer (buna da **çıktı değeri / return value** denir) üreten bir süreçtir. Gerçekleştirilecek belirli işlem, “**operatör / operator**” adı verilen bir sembolle gösterilir.

Örneğin `2 + 3` işleminde:
* `2` ve `3` operand (aynı zamanda literal)
* `+` işareti operatördür.

```cpp
#include <iostream>

int main()
{
    std::cout << 1 + 2 << '\n';
    return 0;
}
```
Buradaki işlemin sonucu olan `3` konsola yazılır. C++'ta bir işlemin çıktısı genellikle "return value / dönüş değeri" olarak adlandırılır.

Yaygın operatörler: 
`+` (toplama), `-` (çıkartma), `/` (bölme), `*` (çarpma), `=` (atama operatörü), `<<` (ekleme operatörü), `>>` (çıkarma operatörü) ve `==` (eşitlik operatörü). 
C++'ta sembol olmayan, anahtar kelime şeklinde operatörler de vardır: `new`, `delete`, `throw` gibi.

*Terminoloji Notu:* İleriki konularda sembol olan operatörlerden bahsederken kelimenin sonuna sembolü eklemek yaygındır (örn: `operator+`, `operator>>`).

---

## 3. Arity (İşlemdeki Eleman Sayısı)

Bir işlemdeki elemanların (operandların) sayısına "arity" denir. Dört farklı arite vardır:

1. **Unary (Tekli İşleç):** Sadece tek bir işlenene etki eder. 
   Örneğin, `-5` verildiğinde, `-` işleci `5` sayısal işlenenini alır ve işaretini ters çevirerek `-5` şeklinde yeni bir çıktı değeri üretir.
2. **Binary (İkili İşleç):** İki işlenene etki eder (sol işlenen işlecin solunda, sağ işlenen sağında yer alır). 
   Örneğin, `3 + 4` ifadesinde, `+` operatörü sol operand olan 3'ü ve sağ operand olan 4'ü alır, toplama işlemi uygulayarak 7 sonucunu verir. Ekleme (`<<`) ve alma (`>>`) operatörleri de ikilidir (sol tarafında `std::cout` veya `std::cin`, sağ tarafında değer/değişken bulunur).
3. **Ternary (Üçlü Operatör):** Üç işlenene etki eder. C++’ta bunlardan sadece bir tane vardır (koşullu operatör), daha sonra ele alınacaktır.
4. **Nullary (Sıfırlı Operatör):** Sıfır işlenene etki eder. C++’ta sadece bir tane vardır (`throw`), daha sonra ele alınacaktır.

*Önemli Not:* Bazı işleçler kullanım şekline göre birden fazla anlama gelebilir. Örneğin `-` işleci, bir sayının işaretini değiştirmek için tekli (unary: `-5`) ya da çıkarma işlemi yapmak için ikili (binary: `4 - 3`) olarak kullanılabilir.

---

## 4. Chaining Operators (İşlemlerin Zincirlenmesi)

İşlemciler, bir işlemcinin çıktısının başka bir işlemcinin girdisi olarak kullanılabileceği şekilde birbirine zincirlenebilir. 

Örneğin, `2 * 3 + 4` ifadesinde:
Çarpma işlemcisi ilk olarak çalışır, 2 ile 3'ü çarparak 6 değerini üretir. Bu 6 değeri, toplama işlemcisinin sol işleneni olur. Ardından toplama operatörü çalışır, 6 ile 4'ü toplayarak 10 sonucunu verir.

C++'ta operatörlerin yürütülme sırası matematikteki gibidir (PEMDAS/BODMAS): Önce parantezler, sonra üsler, çarpma/bölme ve en son toplama/çıkarma. Detaylı öncelik sırası (precedence) ileride işlenecektir.

---

## 5. Return Values (Dönüş Değerleri) ve Side Effects (Yan Etkiler)

C++’taki çoğu operatör, sadece işlenenleri kullanarak bir dönüş değeri hesaplar (`-5` -> `-5` verir, `2 + 3` -> `5` verir). Dönüş değeri üretmeyen çok az operatör vardır.

**Side Effect (Yan Etki):**
Bazı operatörlerin bir dönüş değeri üretmenin ötesinde gözlemlenebilir bir etkisi vardır. Buna yan etki denir.
* `x = 5` ifadesinin, `x` değişkenine 5 değerini atama (değiştirme) yan etkisi vardır. Bu kalıcı bir etkidir.
* `std::cout << 5` ifadesinin, konsola 5 değerini yazdırma yan etkisi vardır.

*Terminoloji Notu:* Günlük dilde "yan etki" genellikle ilaç yan etkisi gibi istenmeyen sonuçları ifade eder. C++'ta ise yan etki, bir fonksiyon veya operatörün yaptığı gözlemlenebilir değişikliktir ve çoğunlukla *ulaşmak istediğimiz asıl amaçtır* (değer atamak veya ekrana yazdırmak gibi).

---

### İleri Düzey Okuyucular İçin (Şimdilik Bilgi Amaçlı)

Öncelikle dönüş değerleri için kullandığımız operatörlerde (`operator+` veya `operator*` gibi) dönen değer bellidir (toplam veya çarpım sonucu). Ancak asıl amacı yan etki yaratmak olan operatörlerin (`operator=` veya `operator<<`) dönüş değerleri ilk bakışta kafa karıştırıcı olabilir.

Hem `operator=` hem de `operator<<` sol tarafındaki işleneni döndürür. Bu, operatörlerin **zincirlenebilmesi** için yapılmıştır.

* **Atama Zinciri:** `x = y = 5` ifadesi `x = (y = 5)` olarak değerlendirilir. İlk olarak `y = 5` işlemi çalışır, `y`'ye değer atanır (yan etki). Bu işlem `y` değerini döndürür ve ardından bu değer `x`'e atanır.
* **Yazdırma Zinciri:** `std::cout << "Hello " << "world!"` ifadesi `(std::cout << "Hello ") << "world!"` şeklinde değerlendirilir. Önce "Hello " yazdırılır. Bu işlem `std::cout` nesnesinin kendisini döndürür, böylece dönen `std::cout` üzerinden ikinci kısımdaki "world!" de yazdırılabilir.

---

## Active Recall Soruları

Günün sonunda bu sorulara notlara bakmadan cevap verebiliyor olman, konunun mantığının oturduğunu gösterir:

1. Literal nedir?
2. `int x {5};` ifadesinde `x` ve `5` nedir?
3. `2 + 3` ifadesinde operand ve operator hangileridir?
4. `x = 5` neden yalnızca bir değer üretmekten ibaret değildir?
5. `std::cout << "Hello " << "world!";` neden zincirlenebilir?
