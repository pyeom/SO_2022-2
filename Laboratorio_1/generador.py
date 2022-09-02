from genericpath import isdir
import random
import os

cant = 20   #Cantidad de archivos a generar

def gen_nombre(cant):
    nombre = ["felipe", "jose", "vicente", "zarko", "rodrigo", "francisca", "miguel", "juan", "tomas"]
    apellido = ["rojas", "montecinos", "kuljis", "flores", "mundaca", "gonzalez", "maturana"]
    lista = []
    for i in range(cant):
        lista.append((random.choice(nombre), random.choice(apellido)))
    return lista

def crear(cant, lista):
    path = "C:/USM/2022-2/SO/Laboratorio_1"
    if not os.path.isdir(path + "/test"):
        os.mkdir(os.path.join(path, "test"))
    for i in range(cant):
        arch_name = lista[i][0] + "_" + lista[i][1] + ".txt"
        file = open(path + "/test/" + arch_name, "w")
        ano = str(random.randint(2019, 2021))
        prioridad = str(random.randint(2500, 15000))
        file.write(ano)
        file.write("\n")
        file.write(prioridad)
        file.close()
    return

crear(cant, gen_nombre(cant))