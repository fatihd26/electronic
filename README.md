# Basit Eşdeğer Direnç Hesaplayıcısı

Bu proje, bir elektrik devresindeki direnç elemanlarını tanımlayarak, bağlı oldukları düğümler üzerinden **eşdeğer direnci** hesaplayan basit bir C++ uygulamasıdır.

---

## Özellikler

- Çoklu direnç elemanlarını devreye ekleyebilme
- Elemanlar arası düğüm bağlantılarını tanımlayabilme
- Ground (toprak) düğümü belirleme
- Devreyi inşa edip eşdeğer direnci çözme
- Sıcaklık parametresi ile dirençlerin davranışını yönetme

---

## Kullanım

Projede `main.cpp` dosyasında örnek bir devre oluşturulmuştur:

```cpp
Circuit c = {};
c.setTemperature(25);

Element* r1 = new Resistor();
r1->setParameters({1000}); // 1kΩ

Element* r2 = new Resistor();
r2->setParameters({2000}); // 2kΩ

// Elemanları devreye ekleme
c.elements.push_back(r1);
c.elements.push_back(r2);

// Bağlantıları yapma
c.connectNodes(*r1,0,*r2,0);
c.connectNodes(*r1,1,*r2,1);

// Toprak düğümü belirleme
c.setGround(*r1,1);

// Devreyi inşa etme ve eşdeğer direnci çözme
c.buildCircuit();
c.solveEqualResistance(r1->getNodeID(0));
```
## Çıktı
```bash
Temperature:25.000000
Resistance:1000.000000
Node positive id:0
Node negative id:1

Temperature:25.000000
Resistance:2000.000000
Node positive id:0
Node negative id:1

Temperature:25.000000
Resistance:3000.000000
Node positive id:0
Node negative id:5

Temperature:25.000000
Resistance:4000.000000
Node positive id:5
Node negative id:1

 R Equal:608.696

```



