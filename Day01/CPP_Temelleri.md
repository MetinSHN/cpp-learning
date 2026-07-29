# C++ ve Bilgisayar Bilimi Temelleri

## 1. Bilgisayarın Çalışma Mantığı
Bilgisayarlar çok hızlıdır ancak sadece makine dilini (0 ve 1'ler) anlarlar.
*   **Program:** Bilgisayara belirli işlemleri sırayla yapmasını söyleyen talimatlar dizisidir.
*   **Donanım:** CPU (işlemci), bellek, giriş/çıkış cihazları ve depolama birimlerinden oluşur.
*   **Yazılım:** Donanım üzerinde çalışan programların tümüdür.

## 2. Makine Dili ve Assembly
*   **Makine Dili:** 0 ve 1'lerden (bit) oluşan, CPU'nun doğrudan anladığı en düşük seviyeli dildir. Her CPU ailesinin (örn. x86, Arm64) kendine özgü, birbiriyle uyumsuz bir makine dili vardır.
*   **Assembly Dili:** Makine dilinin insanlar tarafından biraz daha okunabilir halidir (örn. `mov al`).
    *   CPU doğrudan anlamaz; `Assembler` isimli bir programla makine diline çevrilmesi (derlenmesi) gerekir.
    *   **Avantajları:** İşlemci gücünü en iyi kullanan, hızlı, az yer kaplayan ve donanım/çekirdek programlamada (kernel) kritik bir dildir.
    *   **Dezavantajları:** Taşınabilir (portable) değildir, donanım bilgisi gerektirir, karmaşık kodlar yazmak zordur.

## 3. Yüksek Seviyeli Diller (C, C++, Java vb.)
Yüksek seviyeli diller, altta yatan donanım mimarisinden (CPU/Bellek yönetimi) soyutlanmış, insan diline daha yakın dillerdir.
*   **Avantajları:** Okunması/yazılması kolaydır, donanım bağımsızdır ve taşınabilirdir (cross-platform uyumlu).

## 4. Derleyici (Compiler) ve Yorumlayıcı (Interpreter)
Yüksek seviyeli dillerin makine diline çevrilmesi için iki ana yöntem kullanılır:

### A. Derleyici (Compiler) - Örn: C, C++
*   Yazılan kaynak kodu bir bütün olarak okur ve işletim sisteminin çalıştırabileceği bir makine dili dosyasına (`.exe` gibi) dönüştürür.
*   **Süreç:** `Kaynak Kod` -> `Compiler` -> `Executable File` -> `Donanım`

### B. Yorumlayıcı (Interpreter) - Örn: Perl, Javascript
*   Kodu önceden derlemeden, çalıştırıldığı anda satır satır çevirip uygular.
*   **Dezavantaj:** Her çalıştırmada yorumlama işlemi tekrarlandığı için derlenen dillere göre daha yavaştır ve yorumlayıcının o bilgisayarda yüklü olmasını gerektirir.

## 5. C++ Derleme Süreci
1.  **Kod Yazımı:** C++ kodları `.cpp` uzantılı dosyalara yazılır.
2.  **Derleme (Compiling):** Derleyici, kodun kurallara uygunluğunu (syntax) kontrol eder ve hatasızsa kodu **Object File** (Nesne Dosyası) adı verilen bir dosyada saklar.
3.  **Bağlama (Linking):** `Linker` (Bağlayıcı) devreye girer.
    *   Farklı `.cpp` dosyalarından gelen nesne dosyalarını ve kütüphaneleri birleştirir.
    *   Bağımlılıkları çözer ve nihai çalıştırılabilir dosyayı (`.exe`) üretir.
4.  **Kütüphaneler (Libraries):**
    *   **Standart Kütüphane:** C++ ile birlikte gelen ve I/O (`iostream`) gibi temel işlevleri sağlayan paketlerdir.
    *   **3. Parti Kütüphaneler:** Dışarıdan eklenen, ses veya grafik gibi spesifik işlemleri yapan kütüphanelerdir.

*(Süreç adımları için klasördeki `CPP_Development_Cycle.png` görselini incele).*

---

# C++ Derleme Süreci: Compiler ve Linker Mantığı (The Cherno Part)

## 1. Compiler (Derleyici) Aşaması
Compiler, projedeki her bir `.cpp` dosyasını **diğerlerinden tamamen bağımsız olarak (tek başına)** okur ve makine koduna (Object File - `.obj`) çevirir.
*   Compiler diğer dosyaları umursamaz. Sadece o an çevirdiği dosyada syntax (sözdizimi) hatası olup olmadığına bakar.
*   **Tipik Compiler Hatası:** Bir fonksiyonun 2 parametre beklemesine rağmen senin 1 parametre göndermen (Syntax/Signature mismatch). Derleyici kuralların ihlal edildiğini o anki dosyada görür ve işlemi durdurur.

## 2. Linker (Bağlayıcı) Aşaması
Linker, derleyicinin ürettiği o bağımsız `.obj` dosyalarını alır ve tek bir çalıştırılabilir programa (`.exe`) dönüştürmek için birbirine diker (bağlar).
*   **Tipik Linker Hataları:**
    1.  **Unresolved External Symbol (Bulunamayan Sembol):** Kodu yazarken `Log();` diye bir fonksiyon çağırdın. Compiler "Tamam, böyle bir fonksiyon var diye söz verdin, sana güveniyorum" der ve hata vermez. Ancak Linker tüm dosyaları birleştirirken o fonksiyonun asıl kodunu hiçbir yerde bulamazsa hata fırlatır.
    2.  **Duplication (Çift Tanımlama - ODR İhlali):** Aynı isimde ve aynı yapıda bir fonksiyon, birden fazla dosyada tanımlanmışsa, Linker "Ben hangisini kullanacağım?" diyerek kafası karışır ve hata verir. (Bu durum ileride `static` veya `inline` gibi anahtar kelimelerle yönetilir).

## Özet Kural
*   **Syntax ve kural ihlalleri** -> Compiler yakalar.
*   **Kayıp parçalar veya aynı parçadan iki tane olması** -> Linker yakalar.

## 6. Önemli Kavramlar ve Soru-Cevaplar

**Soru:** `#include <iostream>` silinirse ne olur?
**Cevap:** Derleyici hata verir. Çünkü `std::cout` (ekrana yazdırma) gibi komutların ne anlama geldiğini barındıran "sözlük" silinmiş olur.

**Soru:** İşletim sistemi programı çalıştırdığında hangi kelimeyi arar?
**Cevap:** Her zaman `main` fonksiyonunu arar. Bu, programın ana giriş kapısıdır.

**Soru:** Derleyici de Linker da hata vermediyse ama program çalışırken kapanıyorsa sorun nedir?
**Cevap:** Bu duruma "Çalışma Zamanı Hatası" (Runtime Error) veya mantık hatası denir. Dilbilgisi veya bağlantılar doğrudur ancak kodun içindeki mantıkta bir sorun vardır (örn: sıfıra bölme işlemi).

**Soru:** Bir programın "taşınabilir" (portable) olmaması donanımsal bir sorun mudur?
**Cevap:** Evet. Her CPU ailesinin (Intel x86, Apple ARM) farklı bir makine dili vardır. Birine göre derlenen kod, diğer işlemci tarafından anlaşılamaz.

**Soru:** Benim kodlamayı yaptığım `HelloWorld.cpp` dosyası bilgisayarda tam olarak nerede tutuluyor?
**Cevap:** VS Code'da sol taraftaki dosya gezgininde (Explorer) dosyaya sağ tıklayıp "Reveal in File Explorer" (Dosya Gezgini'nde Göster) diyerek bilgisayardaki fiziksel konumuna (klasörüne) doğrudan ulaşabiliriz.

**Soru:** `.cpp` dosyasının içindeki kodları değiştirip kaydedersem, oluşturulan program (`.exe` dosyası) da otomatik olarak güncellenir mi?
**Cevap:** Hayır, güncellenmez! `.cpp` sadece bir metin belgesidir. Yapılan her değişikliğin programa yansıması için `Yaz -> Kaydet -> Yeniden Derle (Compile) -> Çalıştır` döngüsünün baştan yapılması zorunludur.

**Soru:** Neden aynı anda hem LearnCpp okuyup hem de The Cherno (YouTube) gibi kaynakları izlemiyoruz?
**Cevap:** Çalışma felsefemize göre aynı anda iki farklı anlatım kaynağından eşzamanlı çalışılmaz (odak bölünmesini engellemek için). Biri ana kaynak (LearnCpp) olur, diğeri ise sadece takılan yerlerde destekleyici kaynak olarak kullanılır.