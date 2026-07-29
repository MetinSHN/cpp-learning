# Bölüm 0.8: Hatalar (Compile-time vs. Run-time)

## 1. Compile-time Errors (Derleme Zamanı Hataları)
Derleyicinin (compiler) kodu anlarken karşılaştığı sözdizimi (syntax) hatalarıdır.
- **Neden Olur?** Noktalı virgül (`;`) eksikliği, parantez hataları, `main` fonksiyonunun iki kez yazılması, geçersiz isim kullanımları.
- **Sonuç:** Program derlenmez, `.exe` dosyası oluşmaz. (Örn: `.exe` dosyası arkada açıksa ve derlemeye çalışırsak da yazma hatası alırız).

## 2. Run-time Errors (Çalışma Zamanı Hataları)
Kod başarıyla derlenir, program çalışır ancak mantıksal veya sistemsel bir sorun yüzünden beklenmedik bir şekilde davranır veya çöker.
- **Örnek 1:** Programın çalışıp konsol ekranının anında kapanması. (Bunu çözmek için programı IDE üzerinden doğru modda çalıştırmak veya duraklatma kodu eklemek gerekir).
- **Örnek 2:** Programın çalışması ancak konsolda hiçbir şey yazmaması (Bazen antivirüs programlarının `.exe`'yi taramak için engellemesi/bekletmesi buna sebep olabilir).

---

# Bölüm 0.9: Build Configurations (Derleme Yapılandırmaları)

IDE'nin projeyi nasıl derleyeceğini belirleyen ayar profilleridir.

## Debug Configuration (Hata Ayıklama Modu)
- **Amaç:** Yazılım geliştirme sürecinde hataları bulmayı kolaylaştırmak.
- **Özellikler:** Kod optimizasyonları devre dışıdır. Dosyanın içine fazladan hata ayıklama (debugging) sembolleri ve bilgileri eklenir.
- **Sonuç:** Program daha yavaş çalışır ve dosya boyutu daha büyüktür (Örn: Hello World için 65 KB).

## Release Configuration (Yayın Modu)
- **Amaç:** Programı son kullanıcıya veya performansı test etmeye hazır hale getirmek.
- **Özellikler:** Gereksiz hata ayıklama bilgileri silinir ve derleyici kodu en hızlı çalışacak şekilde optimize eder. Hata durumunda sadece hatanın olduğu bilgisini verir, detaya inmez.
- **Sonuç:** Program çok daha hızlı çalışır ve dosya boyutu çok daha küçüktür (Örn: Hello World için 12 KB).

---

# Bölüm 0.10: Compiler Extensions (Derleyici Uzantıları)

Her derleyici (GCC, Clang, MSVC), standart C++ kurallarının dışına çıkarak kendi özel eklentilerini (extensions) sunar.
- **Sorun:** Bu uzantılar varsayılan olarak açık gelir. Yeni öğrenen biri, bu özel uzantıların standart C++ kuralı olduğunu sanarak yanlış öğrenebilir. Bu kodlar başka bir derleyicide çalıştırıldığında çökebilir veya derlenmeyebilir.
- **Çözüm:** Standart C++ öğrenmek için bu uzantılar kapatılmalıdır.
    - *Visual Studio Ayarı:* Proje Özellikleri -> `C/C++` -> `Language` -> `Conformance mode` (Uyumluluk Modu) -> **Yes (/permissive-)**

---

# Bölüm 0.11: Diagnostics (Teşhis Mesajları) - Warning ve Error

Derleyicinin kodda bulduğu sorunları bize bildirme şeklidir. Hatayı nerede bulduğunu (dosya, satır no) ve ne beklediğini gösterir.

## 1. Error (Hata)
- Kodda dil kurallarını ihlal eden ciddi bir sorun vardır. 
- **Sonuç:** Derleyici işlemi durdurur.

## 2. Warning (Uyarı)
- Kod dil kurallarını ihlal etmez, derlenir ve çalışır ancak derleyici "Burada mantıksal bir hata yapıyor olabilirsin" diyerek uyarır.
- **Kural:** Uyarıların birikmesine asla izin verilmemelidir. Küçük bir uyarı ileride büyük bir çökmenin habercisi olabilir. Uyarının işaret ettiği kod düzeltilmelidir.

### Önerilen Visual Studio Ayarları (Daha Güvenli Kod Yazmak İçin):
1. **Warning Level (Uyarı Seviyesi):** `C/C++` -> `General` -> `Warning Level` -> **Level 4 (/W4)** (EnableAllWarnings KULLANILMAMALIDIR, gereksiz bilgi kirliliği yapar).
2. **Treat Warnings As Errors (Uyarıları Hata Say):** `C/C++` -> `General` -> `Treat Warnings As Errors` -> **Yes (/WX)** (Bu sayede uyarıları çözmeden program derlenmez, disiplin sağlar).
3. **Ekstra Dönüştürme Uyarıları:** `C/C++` -> `Command Line` -> `Additional Options` kısmına `/w44365` eklenir.
4. **Dış Kütüphane Uyarılarını Kapatma:** `C/C++` -> `External Includes` -> `External Header Warning Level` -> **Level 3 (/external:W3)**.

---

# Bölüm 0.12: C++ Standartları

C++ dili sürekli güncellenir (C++11, 14, 17, 20, 23). Standartlar isimlerini çıktıkları yıla göre alır. 
- **Profesyonel Sektör:** Genellikle hataları giderilmiş ve oturmuş olduğu için en son sürümden bir veya iki sürüm öncekini (Örn: C++17 veya 20) kullanır. Bu çapraz platform uyumluluğunu da artırır.
- **Kişisel/Öğrenme Süreci:** Yeni özellikleri öğrenmek için en güncel, kesinleşmiş sürüm kullanılmalıdır. IDE'lerde bu ayarın her yeni projede manuel yapılması gerekir.

---

## Active Recall Soru-Cevapları

**Soru 1:** Compile-time hatası ile Run-time hatası arasındaki temel fark nedir? Hangisi derleyicinin (compiler) işini yapmasını tamamen engeller?
**Cevap:** Compile-time (Derleme Zamanı) hatası, kodun sözdiziminde (syntax) yapılan kural hatalarıdır ve derleyicinin kodu çevirmesini, yani `.exe` dosyasını oluşturmasını tamamen engeller. Run-time (Çalışma Zamanı) hatası ise kod sorunsuz derlendikten sonra, program çalışırken ortaya çıkar; genellikle mantıksal hatalardan (örneğin sonsuz döngüye girmek veya sistem belleğini zorlamak) kaynaklanır.

**Soru 2:** Debug ve Release konfigürasyonları neden farklı dosya boyutları üretir?
**Cevap:** Debug modunda derlenen bir program, geliştiricinin hata ayıklamasını kolaylaştırmak için arka planda fazladan izleme (debugging) bilgileri ve semboller içerir; ayrıca kod optimize edilmez. Release modunda ise bu fazladan hata ayıklama bilgileri atılır ve kod en yüksek hızda çalışacak şekilde optimize edilir, bu yüzden dosya boyutu çok daha küçüktür.