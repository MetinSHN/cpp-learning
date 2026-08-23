# LearnCpp 1.10 - İfadeler (Expressions)

## 1. İfade (Expression) Nedir?
İfade; literallerin, operatörlerin, değişkenlerin ve fonksiyon çağrılarından oluşan ve bir hesaplama yaparak **tek bir değere (sonuca) dönüştürülen (evaluate edilen)** boş olmayan kod sekanslarıdır. 
Bir programın yürütülmesi sürecine *evaluation*, ortaya çıkan sonuca ise *result* ya da *return value* denir. Değerlendirme süreci, geriye tek bir sonuç çıkana kadar devam eder.

```cpp
int five() {
    return 6;
}

int main() {
    int a{ 2 };              // 2: sabit (literal) değer
    int b{ 2 + 1 };          // 2 + 1: computed değer (3'e dönüşür)
    int c{ (2 * 3) + 4 };    // (2 * 3) + 4: computed değer (10'a dönüşür)
    int d{ b };              // b: değişken değeri (3'e dönüşür)
    int e{ five() };         // five(): fonksiyondan dönen değere (6'ya dönüşür)

    return 0;
}
```
*C++ bu farklı yapıların hepsini okur ve tek bir sonuca indirger.*

## 2. İfadeler ve Deyimler (Expressions vs. Statements)
* **İfadeler:** Kendi başlarına derlenemezler. İfadelerin sonunda noktalı virgül (`;`) bulunmaz; mutlaka bir deyimin (statement) parçası olmak zorundadırlar.
* **İfade Deyimi (Expression Statement):** Bir ifadenin sonuna noktalı virgül eklendiğinde elde edilir. İfade deyimi yürütüldüğünde, içindeki ifade değerlendirilmiş olur.
  * *Örnek:* `x = 5` bir ifadedir. `x = 5;` ise derlenebilir bir ifade deyimidir.
* **Faydasız İfade Deyimleri (Useless Expression Statements):** Derlenebilen ancak programın işleyişine hiçbir etkisi olmayan deyimlerdir.
  * *Örnek:* `2 * 3;` kodu derlenir, 6 sonucu hesaplanır ancak bu sonuç kullanılmadığı için gereksiz ve faydasızdır. Sadece `6;` yazmak da aynı şekilde geçerli ama faydasızdır.

## 3. Alt, Tam ve Bileşik İfadeler (Subexpressions, Full Expressions & Compound Expressions)
* **Alt İfade (Subexpression):** Daha büyük bir ifade içinde "işlenen" (operand) olarak görev yapan ifadedir.
  * Örnek: `x = 4 + 5` ifadesinde `x` ve `4 + 5` birer alt ifadedir. `4 + 5` içindeki `4` ve `5` de onun alt ifadeleridir.
* **Tam İfade (Full Expression):** Başka hiçbir ifadenin parçası (alt ifadesi) olmayan ifadedir.
  * Örnek: `2`, `2 + 3` ve `x = 4 + 5` bütün olarak ele alındıklarında birer tam ifadedir.
* **Bileşik İfade (Compound Expression):** İki veya daha fazla operatör içeren ifadelerdir.
  * Örnek: `x = 4 + 5` ifadesinde hem `=` hem de `+` operatörü olduğu için bileşik bir ifadedir. (Fakat `2 + 3` tek operatör içerdiğinden bileşik değildir).

---

## Günlük Kontrol Soruları ve Cevapları

**Soru 1:** `int sonuc = (4 * 2) + 1;` kod satırında derleyicinin işlem yapıp tek bir değere dönüştürdüğü (evaluate ettiği) ifade (expression) tam olarak neresidir ve hangi değere dönüşür?
* **Cevap:** Asıl hesaplanıp dönüştürülen ifade, eşittirin sağ tarafındaki `(4 * 2) + 1` kısmıdır ve evaluate edilerek 9 değerini üretir. (`sonuc` ise değerin atandığı değişkendir.)

**Soru 2:** Sadece bir sayıyı veya değişkeni yazdığımızda (örneğin `5` veya sadece `x`), bunlar kendi başlarına birer ifade (expression) sayılır mı?
* **Cevap:** Evet, sayılır. Literaller kendi sabit değerlerine, değişkenler ise içlerinde tuttukları değere evaluate edilir (dönüşür).
