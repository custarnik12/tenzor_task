# Задание
Есть электронный ключ, при помощи которого можно открывать двери. У ключа и двери может быть опционально указан уровень доступа. Ключом с заданным уровнем доступа можно открыть только дверь с таким же или более низким уровнем доступа, либо дверь, у которой уровень доступа не задан. Ключом с не заданным уровнем доступа можно открыть только двери, у которых уровень доступа не задан. В дополнение к ограничению по уровню доступа для каждой двери могут быть заданы:
- Интервал разрешенного времени доступа (возможно, пустой), например, дверь можно открыть только с 8:00 до 16:00
- Список (набор) запретов на открытие двери, в каждом из элементов которого могут быть указаны:
  * Интервал запрещенного времени доступа (возможно, пустой), например, дверь 
нельзя открыть с 10:00 до 12:00
  * Интервал запрещенных дат доступа (возможно, пустой), например, дверь нельзя 
открыть с 31.12 по 08.01 включительно
## Требуется:
- Реализовать функцию, проверяющую, можно ли открыть заданную дверь заданным 
ключом
  * Выполнить декомпозицию на классы, продумать API. Учесть, что переданное из 
клиентского кода время / дата начала действия разрешения или запрета может больше, чем время / дата окончания, например, с 21:00 до 9:00 или с 25.12 по 10.01
  * Написать unit-тесты
## ЯП
C++ с использованием стандартной библиотеки. Можно использовать любую доступную среду разработки и сборочную систему. Операционная система тоже не важна.

---
## AccessLevel
Из задания понятно, что уровень доступа имеет операцию сравнения, кроме того, есть наименьший уровень доступа - не заданный. Из этого следует, что уровень доступа можно представить точками на луче вещественных чисел, для этого нам подойдет `enum class AccessLevel : unsigned short`. `Unsigned short` был выбран по причине ненадобности отрицательных чисел и экономии памяти, 65536 различаемых уровней доступа - достаточный запас для данной задачи.

## DateTime
Так как в задании не была явно указана требуемая точность определения времени, будем использовать **unix-время**, а именно применим наследованную из __C__ библиотеку `<ctime>`.

## Interval
В задании фигурирует 2 различных интервала:
- интервал 24часов - замкнутая непрерывная область окружности разделенной на 24 части с нулем
- интервал дат без учета года - замкнутая непрерывная область окружности с нулем, разделенная на 365(366 в случае високосного года).
Для реализации создадим абстрактный класс интервала со статическим методом проверки попадания момента времени в данный интервал, от него унаследуем 2 описанных выше вида интервала.

## ElectronicKey
Уровень доступа у электронного ключа задается опционально, следовательно он не используется в конструкторе, а задается сеттером.

## Door
Список запретов будем представлять односвязным списком `forward_list`.

# Тестирование
Для _unit_ тестов были набросаны примитивные проверки без использования _Boost_ или _Gtest_.