| cast | Conversion | Reinterpretation | Upcast | Downcast | Type qualifier |
|:-----|:----------:|:----------------:|:------:|:--------:|:--------------:|
|Implicit|Yes||Yes||||
|static_cast|Yes||Yes|Yes||
|dynamic_cast|||Yes|Yes||
|const_cast|||||Yes|
|reinterpret_cast||Yes|Yes|Yes||
|Legacy C cast|Yes|Yes|Yes|Yes|Yes|

| cast | Semantic check | Reliable at run | Testeed at run |
|:-----|:----------:|:----------------:|:------:|
|Implicit|Yes||Yes||
|static_cast|Yes|||
|dynamic_cast|Yes|Yes|Yes|
|const_cast||||
|reinterpret_cast||||
|Legacy C cast||||