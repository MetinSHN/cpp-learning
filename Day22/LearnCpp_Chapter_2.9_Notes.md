# LearnCpp Chapter 2.9 — Naming collisions and an introduction to namespaces

Arkadaşının evine gideceksin ve bir sokak ismi verdi ama bu sokak ismi farklı bir yerde daha var hangisine gideceksin? İpucu gerekiyor değil mi? Bu durum C++'ta da var tüm tanımlayıcıların belirsiz olmaması gerekir. Aynı programa, derleyici veya bağlayıcının birbirinden ayırt edemeyeceği şekilde iki özdeş tanımlayıcı eklenirse, derleyici veya bağlayıcı bir hata verir. Bu hataya genellikle naming collision/adlandırma çakışması (veya naming conflict/adlandırma çatışması) denir.

Çakışan tanımlayıcılar aynı dosyaya eklenirse, sonuçta bir derleyici hatası oluşur. Çakışan tanımlayıcılar aynı programa ait ayrı dosyalara eklenirse, sonuçta bir bağlayıcı hatası oluşur. Bu hata 2 durumda oluşur:

1. Aynı dosyada aynı isimde 2 ya da daha fazla fonksiyon tanımlanması. Bu durum derleyici hatasına yol açar.
2. Farklı dosyalarda aynı isimde 2 ya da daha fazla fonksiyon tanımlanması. Bu durum derleyicinin her dosya kendi içinde derlenir kısmında sorun çıkarmayacağı için derleyici derleme işini yapar ama linker hata verir.

Programlar büyüdükçe ve daha fazla tanımlayıcı kullandıkça, isim çakışması yaşanma olasılığı önemli ölçüde artar. İyi haber ise, C++’ın isim çakışmalarını önlemek için pek çok mekanizma sunmasıdır. İşlevlerin içinde tanımlanan yerel değişkenlerin birbiriyle çakışmasını önleyen scope region/yerel kapsam, bu mekanizmalardan biridir. Ancak scope region/yerel kapsam, fonksiyon adları için geçerli değildir. Peki, fonksiyon adlarının birbiriyle çakışmasını nasıl önleyebiliriz?

Scope regions: Kapsam bölgesi, kaynak kodun, içinde tanımlanan tüm tanımlayıcıların diğer kapsamlarda tanımlanan adlardan farklı kabul edildiği bir alandır (benzetmemizdeki şehirler gibi). Aynı ada sahip iki tanımlayıcı, ad çakışmasına yol açmadan ayrı kapsam bölgelerinde tanımlanabilir. Ancak, belirli bir kapsam bölgesi içinde tüm tanımlayıcılar benzersiz olmalıdır; aksi takdirde ad çakışması meydana gelir.

Bir fonksiyonun gövdesi, kapsam bölgesine bir örnektir. Aynı ada sahip iki tanımlayıcı, ayrı fonksiyonlarda sorunsuz bir şekilde tanımlanabilir; her fonksiyon ayrı bir kapsam bölgesi sağladığından, çakışma olmaz. Ancak, aynı fonksiyon içinde aynı ada sahip iki tanımlayıcı tanımlamaya çalışırsanız, adlandırma çakışması meydana gelir ve derleyici hata bildirir.

Namespaces: belirsizlikleri gidermek amacıyla kendi içinde adların bildirilmesine veya tanımlanmasına olanak tanıyan başka bir tür kapsam bölgesi (ad alanı kapsamı olarak adlandırılır) sağlar. Bir namespace/ad alanında bildirilen adlar, diğer kapsamlarda bildirilen adlardan izole edilir; böylece bu adların çakışma olmadan var olmaları sağlanır.

Örneğin, aynı bildirimlere sahip iki fonksiyon farklı ad alanları içinde tanımlanabilir ve bu durumda herhangi bir ad çakışması veya belirsizlik ortaya çıkmaz.

Ad alanları yalnızca bildirimler ve tanımlar (örn. değişkenler ve işlevler) içerebilir. Yürütülebilir deyimlere, bir tanımın parçası olmadıkları sürece (örn. bir işlev içinde) izin verilmez.

Ad alanları, büyük bir projede birbiriyle ilişkili tanımlayıcıları gruplandırmak ve bunların yanlışlıkla diğer tanımlayıcılarla çakışmamasını sağlamak amacıyla sıklıkla kullanılır. Örneğin, tüm matematik işlevlerinizi “math” adlı bir ad alanına yerleştirirseniz, bu matematik işlevleriniz “math” ad alanı dışındaki aynı adlı işlevlerle çakışmaz.

The global namespace: C++'ta, bir sınıf, işlev veya ad alanı içinde tanımlanmamış herhangi bir ad, “global namespace/küresel ad alanı” (bazen “the global scope/küresel kapsam” olarak da adlandırılır) adı verilen, örtük olarak tanımlanmış bir ad alanının parçası olarak kabul edilir.

Küresel kapsam içinde bildirilen tanımlayıcılar, bildirildikleri andan dosyanın sonuna kadar geçerlidir.
Değişkenler küresel ad alanında tanımlanabilse de, genellikle bundan kaçınılmalıdır.

The std namespace : C++ ilk kez tasarlandığında, C++ standart kütüphanesindeki tüm tanımlayıcılar (std::cin ve std::cout dahil) std:: önekine gerek kalmaksızın kullanılabilirdi (bunlar küresel ad alanının bir parçasıydı). Ancak bu, standart kütüphanedeki herhangi bir tanımlayıcının, kendi tanımlayıcılarınız için seçtiğiniz (aynı şekilde küresel ad alanında tanımlanmış) herhangi bir adla potansiyel olarak çakışabileceği anlamına geliyordu. Daha önce sorunsuz çalışan bir kod, standart kütüphanenin farklı bir bölümünü eklediğinizde aniden bir isim çakışmasıyla karşılaşabilir. Ya da daha kötüsü, bir C++ sürümünde derlenen kod, bir sonraki C++ sürümünde derlenemeyebilir; çünkü standart kütüphaneye eklenen yeni tanımlayıcılar, halihazırda yazılmış kodla isim çakışmasına neden olabilir. Bu nedenle C++, standart kütüphanedeki tüm işlevleri “std” (“standard”ın kısaltması) adlı bir ad alanına taşımıştır.

Aslında std::cout’un adı gerçekte std::cout değil. Aslında sadece cout’tur ve std, cout tanımlayıcısının parçası olduğu ad alanının adıdır. cout, std ad alanında tanımlandığından, cout adı, std ad alanı dışında (örneğin küresel ad alanında) oluşturduğumuz cout adlı nesnelerle veya işlevlerle çakışmaz.

Küresel olmayan bir ad alanında (örneğin, std ad alanı) tanımlanmış bir tanımlayıcı kullandığınızda, derleyiciye bu tanımlayıcının söz konusu ad alanı içinde yer aldığını belirtmeniz gerekir.”

Bunu yapmanın birkaç farklı yolu vardır.

Explicit namespace qualifier std::: Derleyiciye, std ad alanından cout'u kullanmak istediğimizi belirtmenin en basit yolu, std:: önekini açıkça kullanmaktır. Örneğin:
```cpp
#include <iostream>

int main()
{
    std::cout << "Hello world!"; // "cout" dediğimizde, std ad alanında tanımlanan cout'u kastediyoruz
    return 0;
}
```

:: sembolü, “kapsam çözümleme operatörü” olarak adlandırılan bir operatördür. :: sembolünün solundaki tanımlayıcı, :: sembolünün sağındaki ismin içinde bulunduğu ad alanını belirtir. :: sembolünün solunda herhangi bir tanımlayıcı belirtilmezse, küresel ad alanı varsayılır.

Dolayısıyla, std::cout dediğimizde, “std ad alanında tanımlanan cout” demek istiyoruz.

Bu, `cout`'u kullanmanın en güvenli yoludur; çünkü hangi `cout`'tan bahsettiğimiz konusunda herhangi bir belirsizlik yoktur (std ad alanında bulunan `cout`).

Bir ad alanında tanımlanmış tanımlayıcılara erişmek için açık ad alanı önekleri kullanın.

Bir tanımlayıcı bir ad alanı önekini içerdiğinde, bu tanımlayıcıya “nitelikli ad” denir.

Using namespace std (and why to avoid it): Bir ad alanı içindeki tanımlayıcılara erişmenin bir başka yolu da using yönergesi kullanmaktır. İşte using yönergesi eklenmiş orijinal “Hello world” programımız:
```cpp
#include <iostream>

using namespace std; // this is a using-directive that allows us to access names in the std namespace with no namespace prefix

int main()
{
    cout << "Hello world!";
    return 0;
}
```

Using directive: Ad alanı önekini kullanmadan bir ad alanındaki adlara erişmemizi sağlar. Dolayısıyla yukarıdaki örnekte, derleyici cout tanımlayıcısının ne olduğunu belirlemeye çalıştığında, bunu std::cout ile eşleştirecektir; using yönergesi sayesinde bu tanımlayıcıya sadece cout olarak erişilebilir.

Birçok metin, öğretici ve hatta bazı IDE'ler, programın en başında bir using yönergesinin kullanılmasını önerir veya kullanır. Ancak bu şekilde kullanılması kötü bir uygulamadır ve kesinlikle önerilmez.

Aşağıdaki programı ele alalım:
```cpp
#include <iostream> // std::cout tanımını küresel alana dahil eder

using namespace std; // std::cout'a "cout" olarak erişilebilmesini sağlar

int cout() // küresel ad alanında kendi "cout" işlevimizi tanımlar
{
    return 5;
}

int main()
{
    cout << "Hello, world!"; // Derleme hatası!  Burada hangi cout'u kullanmak istiyoruz?  std ad alanındaki mi, yoksa yukarıda tanımladığımız mı?

    return 0;
}
```

Yukarıdaki program derlenmiyor, çünkü derleyici artık tanımladığımız cout işlevini mi, yoksa std::cout’u mu istediğimizi ayırt edemiyor.

Bir using yönergesini bu şekilde kullandığımızda, tanımladığımız herhangi bir tanımlayıcı, std ad alanında aynı ada sahip herhangi bir tanımlayıcıyla çakışabilir. Daha da kötüsü, bir tanımlayıcı adı bugün çakışmasa bile, gelecekteki dil sürümlerinde std ad alanına eklenecek yeni tanımlayıcılarla çakışabilir. Aslında standart kütüphanedeki tüm tanımlayıcıları std ad alanına taşımamızın asıl amacı da buydu!

Programınızın başında veya başlık dosyalarında using yönergelerini (örneğin, using namespace std;) kullanmaktan kaçının. Bunlar, isim alanlarının başlangıçta eklenme amacına aykırıdır.

Curly braces and indented code: C++'ta, küme parantezleri genellikle başka bir kapsam bölgesi içinde iç içe geçmiş bir kapsam bölgesini sınırlandırmak için kullanılır (küme parantezleri, liste başlatma gibi kapsamla ilgili olmayan bazı amaçlar için de kullanılır). Örneğin, küresel kapsam bölgesi içinde tanımlanan bir fonksiyon, fonksiyonun kapsam bölgesini küresel kapsamdan ayırmak için küme parantezleri kullanır.

Bazı durumlarda, küme parantezlerinin dışında tanımlanan tanımlayıcılar, çevreleyen kapsam yerine yine de küme parantezleriyle tanımlanan kapsamın bir parçası olabilir; fonksiyon parametreleri bunun iyi bir örneğidir.

```cpp
#include <iostream> // imports the declaration of std::cout into the global scope

void foo(int x) // foo is defined in the global scope, x is defined within scope of foo()
{ // braces used to delineate nested scope region for function foo()
    std::cout << x << '\n';
} // x goes out of scope here

int main()
{ // braces used to delineate nested scope region for function main()
    foo(5);

    int x { 6 }; // x is defined within the scope of main()
    std::cout << x << '\n';

    return 0;
} // x goes out of scope here
// foo and main (and std::cout) go out of scope here (the end of the file)
```

İç içe geçmiş bir kapsam bölgesi içinde yer alan kod, hem okunabilirliği artırmak hem de ayrı bir kapsam bölgesi içinde bulunduğunu belirtmek amacıyla geleneksel olarak bir seviye girintilidir.

#include ifadesi ile foo() ve main() işlev tanımları küresel kapsam bölgesinde yer aldığından girintilendirilmez. Her bir işlevin içindeki ifadeler ise işlevin iç içe geçmiş kapsam bölgesi içinde bulunduğundan bir seviye girintilidir.