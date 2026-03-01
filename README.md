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

#include "src/Circuit.h"
#include "src/Resistor.h"
#include "src/VSource.h"


void test(){
    
    Circuit c = {};
    c.setTemperature(25);

    Element * element1 = new Resistor();
    element1->setParameters({1000});

    Element * element2 = new Resistor();
    element2->setParameters({2000});

    Element * element3 = new Resistor();
    element3->setParameters({3000});

    Element * element4 = new Resistor();
    element4->setParameters({4000});

    c.elements.push_back(element1);
    c.elements.push_back(element2);
    c.elements.push_back(element3);
    c.elements.push_back(element4);

    c.connectNodes(*element1,0,*element2,0);
    c.connectNodes(*element1,1,*element2,1);
    c.connectNodes(*element3,0,*element2,0);
    c.connectNodes(*element3,1,*element4,0);
    c.connectNodes(*element4,1,*element2,1);

    c.setGround(*element1,1);

    c.buildCircuit();    
    c.solveEqualResistance(element1->getNodeID(0));

}


int main()
{   
    test();

    return 0;
}
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



