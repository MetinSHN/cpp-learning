# C++ Temelleri: İfadeler ve Yorumlar (LearnCpp 1.1 - 1.2)

## 1.1 Statements (İfadeler) ve Temel Yapılar

*   **Statement (İfade):** Programın belirli bir eylemi gerçekleştirmesini sağlayan en küçük bağımsız komut birimidir. İnsan dilindeki "cümleler" gibidir ve C++'ta genellikle noktalı virgül (`;`) ile biter.
*   **Function (Fonksiyon):** Yukarıdan aşağıya doğru sırayla çalışan ifadeler (statements) bütünüdür. 
    *   Yanındaki `()` parantezleri sayesinde diğer isimlerden ayırt edilir. 
    *   Bir fonksiyonun ismine tanımlayıcı (**identifier**) denir.
*   **main() Fonksiyonu:** İstisnasız **her** C++ programında bulunmak zorundadır. Program başlatıldığında işletim sistemi doğrudan bu fonksiyonu arar ve içindeki kodları yukarıdan aşağıya çalıştırır. Kapsamı (sınırları) `{}` süslü parantezlerle belirlenir.
*   **Syntax (Sözdizimi):** Kodun derleyici tarafından anlaşılabilmesi için uyulması gereken dilbilgisi kurallarıdır. En yaygın syntax hataları eksik noktalı virgül (`;`) veya kapatılmamış süslü parantezdir (`}`). 
    *   *Not:* Bir syntax hatasında IDE'ler (özellikle Visual Studio) hatayı bazen bir sonraki satırda gösterebilir. Hata yokmuş gibi görünüyorsa her zaman bir üst satıra bakılmalıdır.

### C++ Standart Kütüphanesi ve Giriş/Çıkış
*   **Kütüphane (Library):** Başka programlarda yeniden kullanılmak üzere paketlenmiş önceden derlenmiş kod koleksiyonudur.
*   `#include <iostream>`: Ön işleyici (preprocessor) komutudur. Ekrana yazı yazdırmak ve girdi almak için gerekli olan standart C++ kütüphanesini kodumuza dahil eder. Bu olmadan `std::cout` kullanılamaz, derleyici bunun ne anlama geldiğini bilemez.
*   `std::cout`: "Character Output" (Karakter Çıkışı) anlamına gelir. Yanındaki `<<` operatörü ile veriyi konsola gönderir.
*   `return 0;`: Programın çalışması bittiğinde işletim sistemine "İşler yolunda gitti, hatasız kapandım" mesajını (0 değerini) gönderir.

### Metinler ve Karakterler
*   **Character:** Harfler, işaretler veya rakamlar (En basit iletişim birimi).
*   **Text / String:** Karakterlerin birleşmesinden oluşan metin dizileridir. C++'ta kodlar "plain text" (düz metin) olarak yazılır; kalınlaştırma, renk gibi biçimlendirmeler yoktur.
*   **Control Characters (Kontrol Karakterleri):** Ekranda görsel bir karşılığı olmayan ancak özel işlevleri olan karakterlerdir (Örn: Escape, Backspace).

---

## 1.2 Comments (Yorum Satırları)

Yorumlar, programcının okuması için koda eklenen ve **derleyici (compiler) tarafından tamamen yok sayılan** notlardır.

### Yorum Tipleri
1.  **Tek Satırlı Yorum (`//`):** Kendisinden sonraki satırın sonuna kadar olan kısmı yorum yapar. Kodun sağına eklenecekse okunabilirliği artırmak için `Tab` tuşu ile hizalanması iyi bir pratiktir. Ancak kod uzunsa, yorumu kodun bir üst satırına yazmak daha okunaklıdır.
2.  **Çok Satırlı Yorum (`/* */`):** (PHP'deki mantıkla aynıdır). Bu iki işaret arasındaki her şeyi yorum yapar. 
    *   *Kritik Kural:* Çok satırlı yorumlar **yuvalanamaz** (nested yapılamaz). İç içe `/* /* */ */` kullanırsanız derleyici ilk gördüğü `*/` işaretinde yorumu bitirir ve sonrasını kod sanarak hata verir.

### Yorum Yazma Kuralları (Ne zaman kullanılmalı?)
Kurumsal ve temiz bir kod yazmak için yorumlar şu amaçlarla kullanılır:
1.  **Kütüphane/Program Seviyesi:** Bu dosya veya kütüphane genel olarak ne işe yarıyor? (Genelde dosyanın en üstüne yazılır).
2.  **Fonksiyon Seviyesi:** Bu fonksiyon amacı nasıl gerçekleştiriyor?
3.  **İfade (Statement) Seviyesi (EN ÖNEMLİSİ):** Kodun **NE** yaptığını değil, **NİYE (NEDEN)** yaptığını açıklar. 
    *   *Kötü Yorum:* `x = 0; // x'i 0 yapar.` (Bunu zaten koddan anlıyoruz).
    *   *İyi Yorum:* `x = 0; // Yeni tur başladığı için oyuncu skoru sıfırlandı.`

### Commenting Out (Kodu Yorum Satırına Almak)
Bir kodu silmek yerine geçici olarak derleyiciden gizleme işlemidir. Hata ayıklama (debugging) için hayat kurtarıcıdır:
*   Yarım kalan bir kodu programı çalıştırabilmek için gizlemek.
*   Hata veren satırı izole edip sorunun kaynağını bulmak.
*   Eski kodu silmeden, yeni kodun çalıştığından emin olana kadar yedeğini tutmak.

## Active Recall ve Yapay Zeka Değerlendirmesi

**Soru 1: "Kötü yorum (bad comment)" ile "iyi yorum (good comment)" arasındaki temel fark nedir? Neden kodun *ne* yaptığını açıklamak yerine *neden* yaptığını açıklamalıyız?**

*Cevabım ve Teknik Analiz:* 
Kodun "ne" yaptığını zaten kodun kendisinde (syntax) açıkça görüyoruz. Bunu yorum satırında tekrar etmek bir nevi "anlatım bozukluğu" yaratır ve kodu kirletmekten başka bir işe yaramaz. İyi bir yorum satırı, dışarıdan bakıldığında anlaşılmayan o soyut kararı, yani yazarın o kodu "niye" öyle yazdığını (intent) açıklamalıdır. Kod nasıl çalıştığını, yorum ise neden o şekilde tasarlandığını anlatır.
