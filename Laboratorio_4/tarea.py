import threading
import datetime


# Copy paste para logs en los archivos de texto
'''
        semaforo_logs.acquire()
        f = open("partida", 'w')
        buffer = "Jugador" + + datetime.now.strftime("%H:%M:%S")
        f.write(buffer)
        f.close()
        semaforo_logs.release()
'''

# Semaforos

semaforo_juego = threading.Semaphore(120)
semaforo_logs = threading.Semaphore(1)

# Partida Estándar
semaforo_estandar = threading.Semaphore(15)
cola_estandar = threading.Semaphore(7)
estandar_ready = threading.Semaphore(0)

# Partida Versus
semaforo_versus = threading.Semaphore(2)
cola_versus = threading.Semaphore(4)
versus_ready = threading.Semaphore(0)

# Partida Rápida
semaforo_rapida = threading.Semaphore(10)
cola_rapida = threading.Semaphore(8)
rapida_ready = threading.Semaphore(0)

# Partida Especial Navidad
semaforo_navidad = threading.Semaphore(12)
cola_navidad = threading.Semaphore(10)
navidad_ready = threading.Semaphore(0)


# Constructores
def partida_estandar():
    while (1):
        cola_estandar.acquire()

        semaforo_logs.acquire()
        f = open("PartidaEstandar.txt", 'w')
        buffer = "Jugador" + + datetime.now.strftime("%H:%M:%S")
        f.write(buffer)
        f.close()
        semaforo_logs.release()


def partida_versus():
    while (1):
        cola_versus.acquire()

        semaforo_logs.acquire()
        f = open("PartidaVersus.txt", 'w')
        buffer = "Jugador" + + datetime.now.strftime("%H:%M:%S")
        f.write(buffer)
        f.close()
        semaforo_logs.release()


def partida_Rapida():
    while (1):
        cola_rapida.acquire()

        semaforo_logs.acquire()
        f = open("PartidaRapida.txt", 'w')
        buffer = "Jugador" + + datetime.now.strftime("%H:%M:%S")
        f.write(buffer)
        f.close()
        semaforo_logs.release()


def partida_navidad():
    while (1):
        cola_navidad.acquire()

        semaforo_logs.acquire()
        f = open("PartidaEspecialNavidad.txt", 'w')
        buffer = "Jugador" + + datetime.now.strftime("%H:%M:%S")
        f.write(buffer)
        f.close()
        semaforo_logs.release()




