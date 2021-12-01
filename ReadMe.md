# Домашнее задание номер 4
Вариант: 173 Номер задачи: 5 Номер функции: 13
# Отчет по заданию 4

## Составление программы по условию:
**Обобщенный артефакт, используемый в задании:** Квадратные матрицы с действительными числами

**Базовые альтернативы
(уникальные параметры,
задающие отличительные
признаки альтернатив):**
1. Обычный двумерный
   массив
2. Диагональная (на основе
   одномерного массива)
3. Нижняя треугольная
   матрица (одномерный массив с формулой пересчета)

**Общие для всех альтернатив переменные:** Размерность – целое число

**Общие для всех альтернатив функции:** Вычисление среднего арифметического (действительное число)

**Обработка контейнера:** Упорядочивание элементов контейнера по убыванию используя Shaker Sort.
В качестве ключей для сортировки и других действий используются результаты функции, общей для всех альтернатив.

## Характеристики программы
**Число модулей**: 6 

**Результаты тестирования:**
1. test_in_1_bad.txt - exception
2. test_in_2_bad.txt - 0.0001s - ignore problem
3. test_in_5.txt - 0.00002s
4. test_in_10.txt - 0.00004s
5. test_in_100.txt - 0.0001s
6. test_in_1000.txt - 0.002s
7. test_in_10000.txt - 0.168s

# Сравнение с предыдущими реализациями

Программа с использованием ассемблера nasm для наиболее ресурсоемких частей задания оказалась в 80 раз быстрее чем программа на python (и в 150 раз быстрее чем программы на С и С++, но как я уже писал в прошлом сравнении это проихошло из-за того что в коде на питоне я оптимизровал количество вызовов функции Average до 1 на каждую матрицу, если бы изначально это было сделано, то эта программа была бы в около 3 раза быстрее чем прогрмма на С++). Но, конечно, писать код на ассемблере и дебажить его очень ресурсоемкая работа. 

На мой взгляд ниболее подходящим подходом для данной задачи является динамически типизированный.
