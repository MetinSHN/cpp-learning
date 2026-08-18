# C++ Boşluklar (Whitespace) ve Temel Biçimlendirme (LearnCpp 1.8)

## 1. Öğrenme Soruları ve Cevapları
**Soru 1:** Derleyici (compiler) kodumuzdaki o devasa boşlukları (boş satırlar, tab'lar, aralara konan space'ler) gördüğünde arka planda temelde bunlara ne yapar?
**Cevap 1:** Bunları ifadeleri birbirinden ayırmak, keyword'leri birbirinden ayırmak için kullandığımızı düşünür. Ayırma işlemi bittikten sonra geri kalan fazla boşlukları yok sayar.

**Soru 2:** Madem derleyici bizim o bıraktığımız boşlukları hiç umursamıyor, neden tüm kodumuzu dümdüz tek bir satıra yazmıyoruz?
**Cevap 2:** Muhatabı biziz çünkü kodu aylar sonra açıp baktığımızda okumakta zorluk çekmememiz için ya da hatalarımızı kolayca bulmak için ayrı satırlara yazıyoruz. Düşünsene 1 satır kodun var ama milyonlarca karakter ve hata yapmışsın; milyonlarca karakterin arasında o kısmı mı arayacaksın?

---

## 2. Whitespace (Boşluk) Nedir?
Whitespace: "Boşluk" yani bize biçimlendirme amacıyla kullanılan karakterleri ifade eden bir terimdir. C++'ta öncelikle bunlar sekmeler ve satırlar sonlarını ifade eder. Genelde 3 anlamda kullanılırlar: belirli dil ögelerini ayırmak, metin içinde ve kodu biçimlendirmek.

### Some language elements must be whitespace-separated
Dilin elementlerini birbirinden ayırt etmek için kullanılır. Compiler'ın bunları ayrı parça olarak görebilmesi için yapılır bu işlem.

int x; // x değişkeni ve int keywordünü birbirinden ayırt etmede kullanıldı.

intx olsa bunu ayrı bir keyword, fonksiyon ya da değişken olarak arayacaktı ama sonucunda hata verecekti. Bu durum şunda da geçerli:

int main();
intmain();

Boşluk gereken yerlerde ne kadar boşluk kullandığımızın önemi yoktur, derleyici bunu ayırt eder.

int x; 
ile 
int                      x; 
                int
z;          

aynı şeydir hata vermez.

Bazı durumlarda, satır sonları ayırıcı olarak kullanılır. Tek satırlık yorumlar, bir satır sonu ile sona erer.

std::cout << "Hello World"; // Burası yorum satırı
burası artık yorum satırına dahil değildir

Preprocessor'lar ayrı satırlarda kullanılmalıdırlar:
#include <iostream>
#include <string>

### Quoted text takes the amount of whitespace literally
" " arasında işler değişiyor.

std::cout << "Hello World"; 
ile 
std::cout << "Hello                  World";
birbirinden farklıdır.

Yeni satıra geçmek " " içinde yasaklıdır.

std::cout << "Hello
World"; // bu kod hatalıdır.

Sadece boşluk karakterleriyle (boşluk, sekme veya satır sonu) ayrılmış alıntı metinleri birleştirilecektir:
std::cout << "Hello "
"World!"; // ekranda "Hello World!" yazar

### Using whitespace to format code
Kodumuzu daha okunaklı kılmak adına boşlukları kullanabiliriz.

#include <iostream>
int main(){std::cout<<"Hello World!";return 0;}

mi daha okunaklı yoksa

#include <iostream>

int main(){
    std::cout << "Hello World!"; 
    return 0;
}

Bu ise daha iyisi:

#include <iostream>

int main()
{
    std::cout << "Hello World!";

    return 0;
}

İstenirse ifadeler birden fazla satıra bölünebilir:

#include <iostream>

int main()
{
    std::cout
        << "Hello world"; // works fine
    return 0;
}

Bu yöntem uzun ifadelerde yardımcı olabilir.

## 3. Basic formatting
Diğer dillerin aksine C++ bizi bazı kısıtlamalarla zorlamıyor, bu yüzden C++ için boşluk özgürlüğü dili diyebiliriz.

Bu hem avantaj hem de dezavantaj. Bir yandan istediğinizi yapma özgürlüğü tanıyor ama bazen de dikkat dağıtıcılığı vb. sebepleriyle dezavantaj. Bu yüzden bizim için en iyisi en iyi stiller, en okunaklı ve en tutarlı stillerdir.

**Bazı tavsiyeler şunlardır:**

**1. Girinti için hem sekme hem de boşluk kullanmak uygundur.** 
Girintilerin Python'da önemli olduğunu hatırlıyorum çünkü orada ; ya da {} yok. Girintiler önemli. Bazı insanlar kodu tam hizalamak için boşluğu kullanır ki ben de tab'la hizalayamadığım bazı kodları boşlukla hizalıyordum. Tab ile yaptığımızın uzunluğunu IDE tarafından ayarlayabiliyoruz. Bu tamamen kişisel tercih.

**2. Köşeli parantez için 2 stil var (ben eskiden 1.yi kullanıyordum).**

Aynı satırda olması (fonksiyon satırıyla):
int main() {

}
Bu, dikey boşlukların sayısını azaltır ve daha fazla kodu ekrana sığdırmamıza yardımcı olur.

Farklı satırda olması (fonksiyon satırıyla):
int main()
{

}
Bu da okunabilirliği artırıyor ve parantez çiftlerini hep aynı seviyede girintilediğimiz için hata ihtimalini azaltır, hata tespitini kolaylaştırır.

**3. Her ifade ait oldukları köşeli parantezin 1 fazla girintisi hizasında durmalıdır.**
int main()
{
    std::cout << "Hello World!"; // 1 tab uzakta yani 4 boşluk
}

**4. Satırlar çok uzun olmamalı.** 
Genel olarak 80 karakter maximum olarak standart alınır. Bir satır bu uzunluğu aşacaksa, (uygun bir noktadan) birden fazla satıra bölünmelidir. Bu, sonraki her satırı fazladan bir sekme ile girintilemek suretiyle ya da satırlar birbirine benziyorsa, üstündeki satırla hizalamak suretiyle yapılabilir (hangisi okunması daha kolaysa).

int main()
{
    std::cout << "This is a really, really, really, really, really, really, really, "
        "really long line\n"; // one extra indentation for continuation line

    std::cout << "This is another really, really, really, really, really, really, really, "
                 "really long line\n"; // text aligned with the previous line for continuation line

    std::cout << "This one is short\n";
}
Bu şekilde okumak daha kolay olacaktır.

**5. Uzun bir satır bir işleçle (örn. << veya +) bölünürse, işleç mevcut satırın sonuna değil, bir sonraki satırın başına yerleştirilmelidir.**
std::cout << 3 + 4
    + 5 + 6
    * 7 * 8;

**6. Değerleri veya yorumları hizalayarak ya da kod blokları arasına boşluk ekleyerek kodunuzu daha okunaklı hale getirmek için boşluk karakterlerini kullanın.**

cost = 57;
pricePerItem = 24;
value = 5;
numberOfItems = 17;

yerine:

cost          = 57;
pricePerItem  = 24;
value         = 5;
numberOfItems = 17;

kullan. Ya da:

std::cout << "Hello world!\n"; // cout lives in the iostream library
std::cout << "It is very nice to meet you!\n"; // these comments make the code hard to read
std::cout << "Yeah!\n"; // especially when lines are different lengths

yerine:

std::cout << "Hello world!\n";                  // cout lives in the iostream library
std::cout << "It is very nice to meet you!\n";  // these comments are easier to read
std::cout << "Yeah!\n";                         // especially when all lined up

kullan. Ya da:

// cout lives in the iostream library
std::cout << "Hello world!\n";
// these comments make the code hard to read
std::cout << "It is very nice to meet you!\n";
// especially when all bunched together
std::cout << "Yeah!\n";

yerine:

// cout lives in the iostream library
std::cout << "Hello world!\n";

// these comments are easier to read
std::cout << "It is very nice to meet you!\n";

// when separated by whitespace
std::cout << "Yeah!\n";

Kullan. Biz bu sistemi zaten daha önce yorum satırlarında da görmüştük.

Örneklerde kullandığımız stili benimsemenizi şiddetle tavsiye ederiz. Bu stil, milyarlarca satırlık kod üzerinde binlerce programcı tarafından pratikte test edilmiş ve başarıya yönelik olarak optimize edilmiştir.

*Tek bir istisna:* Başka birinin kod tabanında çalışıyorsanız, o kişinin stilini benimseyin. Kendi tercihlerinize göre hareket etmektense tutarlılığı öncelikli tutmak daha iyidir.

## 4. Automatic formatting

Çoğu modern IDE, kodunuzu yazarken onu biçimlendirmenize yardımcı olur (örneğin, bir fonksiyon oluşturduğunuzda IDE, fonksiyon gövdesindeki ifadeleri otomatik olarak girintiler).

Ancak kod ekleyip çıkardığınızda, IDE'nin varsayılan biçimlendirme ayarlarını değiştirdiğinizde veya farklı bir biçimlendirmeye sahip bir kod bloğunu yapıştırdığınızda, biçimlendirme bozulabilir. Bir dosyanın tamamı veya bir kısmı için biçimlendirmeyi düzeltmek zahmetli bir iş olabilir. Neyse ki modern IDE'ler genellikle, (fareyle seçtiğiniz) bir bölümü veya dosyanın tamamını yeniden biçimlendiren otomatik bir biçimlendirme özelliği sunar.

**Visual Studio kullanıcıları için:**
Visual Studio'da otomatik biçimlendirme seçenekleri Edit > Advanced > Format Document ve Edit > Advanced > Format Selection menüleri altında bulunur.

**Code::Blocks kullanıcıları için:**
Code::Blocks'ta otomatik biçimlendirme seçeneklerine Sağ tıklama > Format use AStyle yoluyla ulaşılabilir.

Daha kolay erişim sağlamak adına, aktif dosyayı otomatik biçimlendirmek için bir klavye kısayolu atamanızı öneririz.
Kodu otomatik olarak biçimlendirmek için kullanılabilecek harici araçlar da mevcuttur; clang-format bunlardan popüler olan biridir.

**En iyi uygulama:**
Kodunuzun biçimlendirme stilini tutarlı tutmak için otomatik biçimlendirme özelliğini kullanmanız şiddetle tavsiye edilir.

## 5. Stil kılavuzları (Style Guides)
Stil kılavuzu; (bazen keyfi olabilen) programlama kurallarını, biçimlendirme yönergelerini ve en iyi uygulamaları içeren, özlü ve belirli bir yaklaşımı benimseyen bir belgedir. Stil kılavuzunun amacı, bir projedeki tüm geliştiricilerin tutarlı bir şekilde programlama yapmasını sağlamaktır.

Yaygın olarak başvurulan bazı C++ stil kılavuzları şunlardır:
* Bjarne Stroustrup ve Herb Sutter tarafından sürdürülen C++ Core Guidelines.
* Google.
* LLVM.
* GCC/GNU.

Güncel olmaları ve geniş çapta uygulanabilirlikleri nedeniyle genellikle C++ Core Guidelines'ı tercih ediyoruz.