# LearnCpp 2.5: Introduction to local scope

## Yerel Değişkenler (Local Variables)
Fonksiyonun içinde veya parametre listesinde tanımlanan değişkenlere **yerel değişken** (local variable) denir.

```cpp
int add(int x, int y) // x ve y parametreleri yerel değişkendir
{
    int z {x + y}; // z de yerel değişkendir.
    return z;
}
```

---

## Kapsam (Scope) ve Ömür (Lifetime)

### Kapsam (Scope)
Bir değişkenin kaynak kod içinde **nerede görülebileceğini ve kullanılabileceğini** belirleyen **derleme zamanı (compile-time)** özelliğidir.
- Yerel değişkenler, tanımlandıkları süslü parantezin `{}` veya parametre listesinin sonunda **kapsam dışına (out of scope)** çıkarlar.
- Kapsam dışındaki bir değişkeni kullanmaya çalışmak derleme hatası verir.
- **Fonksiyon Bağımsızlığı:** İki farklı fonksiyonda aynı isimde (örneğin `x`) yerel değişken olabilir. Bunlar birbirinden tamamen bağımsızdır çünkü kapsamları çakışmaz.

### Ömür (Lifetime)
Bir değişkenin **bellekte yer kapladığı süreyi** belirleyen **çalışma zamanı (runtime)** özelliğidir.
- Değişken oluşturulduğunda ömrü başlar.
- Değişken kapsam dışına çıktığında yok edilir (destroyed) ve bellekte kapladığı yer serbest bırakılır. 
- Yok edilmiş bir değişkeni kullanmak tanımsız davranışa (undefined behavior) yol açar.
- Yok edilme sırası, **oluşturulma sırasının tersidir**. (Son giren ilk çıkar - LIFO)

*Özetle: Kapsam, değişkenin adını nerede kullanabileceğimizi söyler; ömür ise değişkenin bellekte ne kadar süre yaşadığını.*

---

## Parametre mi, Yerel Değişken mi?
- Değişkenin ilk değeri **fonksiyonu çağıran (caller)** tarafından verilecekse: **Parametre** kullan.
- Aksi takdirde, sadece fonksiyonun iç işleyişi için lazımsa: **Yerel değişken** kullan.
- **En İyi Pratik:** C++'ta değişkenleri mümkün olduğunca **kullanılacakları yere en yakın yerde** tanımlayın.

---

## Geçici Nesneler (Temporary Objects)
Sadece kısa bir süreliğine (örneğin bir fonksiyonun dönüş değerini saklamak için) derleyici tarafından otomatik oluşturulan **isimsiz** nesnelerdir.
- İsimleri (tanımlayıcıları) olmadığı için **kapsamları (scope) yoktur**.
- İçinde bulundukları ifadenin (statement) sonunda anında yok edilirler.
- Modern C++ (özellikle C++17 sonrası), performansı artırmak için mümkün olan her yerde bu geçici nesnelerin yaratılmasını atlar (copy elision).

---

## Active Recall

**Soru 1:** Bir değişkenin "Scope" (Kapsam) özelliği derleme zamanı (compile-time) özelliği midir, yoksa çalışma zamanı (runtime) özelliği midir?
**Cevap 1:** Scope derleme zamanı (compile-time) özelliğidir. Derleyici değişkenin nerede kullanılıp kullanılamayacağını kod yazılırken kontrol eder.

**Soru 2:** Bir değişkenin "Lifetime" (Ömür) kavramı neyi ifade eder?
**Cevap 2:** Çalışma zamanında değişkenin oluşturulmasıyla başlayan ve bellekten yok edilip (destroy) yerinin serbest bırakılmasıyla biten süreyi ifade eder.

**Soru 3:** İki farklı fonksiyonda (`main` ve `add`) aynı isimli (`x`) yerel değişkenler kullanılabilir mi? Neden?
**Cevap 3:** Evet kullanılabilir. Çünkü fonksiyonların kapsamları (scope) ayrıdır ve bir fonksiyon diğerinin içindeki değişkenleri göremez. Bu özellik fonksiyonların bağımsız olmasını sağlar.

**Soru 4:** "Geçici nesnelerin (temporary objects) kapsamı (scope) yoktur" ifadesi neden doğrudur?
**Cevap 4:** Çünkü geçici nesnelerin kaynak kodda bir ismi (tanımlayıcısı) yoktur. Kapsam (scope), isimlerin nerede geçerli olduğuyla ilgili bir kavramdır.
