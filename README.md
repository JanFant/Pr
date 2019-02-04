## Каталог размещения проекта
#### Основной XML описания системы : **Main.xml**
+ `general` - описание системы
  + `name` - имя системы
  + `description` - описание/комментарий
  + `defdrv` - указание каталога с Xml драйверов
  + `simul` - режим работы (от имитатора (*yes*) или устройств (*no*))
  + `ip` - ip устройства где запускается имитатор
  + `port` - port по которому происходит подключение
+ `subs` - описание подсистемы
  + `name` - имя подсистемы
  + `scheme` - путь до Тепрольной схемы
  + `id` - номер подсистемы
  + `file` - XML описание подсистемы
  + `description` - описание/комментарий   
  + `main` - основной ip (ip первого (левого) модуля **ФП** в корзине)
  + `second` - резервный ip (ip второго (правого) модуля **ФП** в корзине)
  + `path` -  каталог в котором расположенны файлы подсистемы
  + `step` - время цикла в милисекундах
  + `result` - каталог в который собирается **master.h**

##### Каждый каталог подсистемы содержит:
+ каталог **`scheme`** - в нём хранятся файлы Тепрольной схемы, промежуточные файлы для сборки **master.h** полученные из Тепрола
+ каталог **`src`** - в нём хранятся **master.h**
+ **`*fp.xml`** - фаил описания подсисеты в нем указываются:
    * `variable` - фаил xml с описанием всех переменных в подсисетме
    * `saves` - фаил xml с переменным ЭСППЗУ
    * `devices` - фаил xml в котором описана привязка переменных к каналам устройств
    * `modbus` - фаил(ы) xml в котором описан интерфейс Modbus. Для него указываются следующие атрибуты
      *  `name` - имя интерфейса Modbus
      *  `description` - описание/комментарий к интерфейсу
      * `type` - тип интерфейса Modbus (**slave / master**)
      * если тип интерфейса `master` - указываются `ip1 / ip2` 
      * `port` -  port подключения для Modbus
      * `step` - время опроса интерфейса Modbus
      * `xml` - путь до необходимых Xml
