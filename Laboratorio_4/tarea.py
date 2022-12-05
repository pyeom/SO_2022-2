import threading
import time
import datetime
import random

#ESTANDAR = 0
#VERSUS = 1
#RAPIDA = 2
#NAVIDAD = 3

# Copy paste para logs en los archivos de texto
'''
        f = open("partida", 'w')
        semaforo.acquire()
        tiempo1 = datetime.now().strftime("%H:%M:%S")
        semaforo.release()
        tiempo2 = datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo1 + tiempo2 
        semaforo_logs.acquire()
        f.write(buffer)
        semaforo_logs.release()
        f.close()
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


#barriers
barrier_estandar = threading.Barrier(15)
barrier_estandar_salida = threading.Barrier(15)
barrier_versus = threading.Barrier(2)
barrier_versus_salida = threading.Barrier(2)
barrier_rapida = threading.Barrier(10)
barrier_rapida_salida = threading.Barrier(10)
barrier_navidad = threading.Barrier(12)
barrier_navidad_salida = threading.Barrier(12)

texto_lobby = open("Lobby.txt", "w")
texto_rapida = open("PartidaRapida.txt", "w")
texto_estandar = open("PartidaEstandar.txt", "w")
texto_versus = open("PartidaVersus.txt", "w")
texto_navidad = open("PartidaEspecialNavidad.txt", "w")
texto_salida = open("Salida.txt", "w")

texto_lobby.close()
texto_estandar.close()
texto_navidad.close()
texto_rapida.close()
texto_versus.close()
texto_salida.close()



def juego(jugador, sala):
    global jugadores_estandar
    #Entra al Lobby
    semaforo_juego.acquire()

    semaforo_logs.acquire()
    tiempo1 = datetime.datetime.now().strftime("%H:%M:%S")
    print("entra el jugador ", jugador, "al lobby")
    semaforo_logs.release()

   
    #Revisa de que sala es
    if sala == 0:           # Partida Estándar
        #Entra a la cola
        cola_estandar.acquire()
        semaforo_logs.acquire()
        f = open("Lobby.txt", 'a')
        tiempo2 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo1 + ", " + "Partida Estándar, " + tiempo2 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_logs.acquire()
        print("el jugador ", jugador, "entra a la cola estandar")
        tiempo3 = datetime.datetime.now().strftime("%H:%M:%S")
        semaforo_logs.release()

        #Entra a la partida y sale de la cola
        semaforo_estandar.acquire()
        cola_estandar.release()

        semaforo_logs.acquire()
        f = open("PartidaEstandar.txt", 'a')
        tiempo4 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo3 + ", " + tiempo4 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_logs.acquire()
        print("jugador", jugador, "esperando a que comience la partida")
        semaforo_logs.release()
        #Esperando a tener suficientes jugadores
        try:
            barrier_estandar.wait()
        except threading.BrokenBarrierError:
            barrier_estandar.reset()
        #Comienza la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " entra la partida estandar")
        semaforo_logs.release()
        time.sleep(7)
        #Termina la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " sale de la partida estandar")
        semaforo_logs.release()
        try:
            barrier_estandar_salida.wait()
        except threading.BrokenBarrierError:
            barrier_estandar_salida.reset()
        semaforo_logs.acquire()
        f = open("Salida.txt", 'a')
        tiempo5 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo5 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()
        semaforo_estandar.release()


    elif sala == 1:         # Partida Versus
        #Entra a la cola
        cola_versus.acquire()
        semaforo_logs.acquire()
        f = open("Lobby.txt", 'a')
        tiempo2 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo1 + ", " + "Partida Versus, " + tiempo2 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_logs.acquire()
        print("el jugador ", jugador, "entra a la cola Versus")
        tiempo3 = datetime.datetime.now().strftime("%H:%M:%S")
        semaforo_logs.release()

        #Entra a la partida y sale de la cola
        semaforo_versus.acquire()
        cola_versus.release()

        semaforo_logs.acquire()
        f = open("PartidaVersus.txt", 'a')
        tiempo4 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo3 + ", " + tiempo4 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()


        semaforo_logs.acquire()
        print("jugador", jugador, "esperando a que comience la partida")
        semaforo_logs.release()
        #Esperando a tener suficientes jugadores
        try:
            barrier_versus.wait()
        except threading.BrokenBarrierError:
            barrier_versus.reset()
        #Comienza la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " entra la partida versus")
        semaforo_logs.release()
        time.sleep(3)
        #Termina la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " sale de la partida versus")
        semaforo_logs.release()
        try:
            barrier_versus_salida.wait()
        except threading.BrokenBarrierError:
            barrier_versus_salida.reset()
        
        semaforo_logs.acquire()
        f = open("Salida.txt", 'a')
        tiempo5 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo5 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_versus.release()

    elif sala == 2:         # Partida Rápida
        cola_rapida.acquire()
        semaforo_logs.acquire()
        f = open("Lobby.txt", 'a')
        tiempo2 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo1 + ", " + "Partida Rápida, " + tiempo2 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_logs.acquire()
        print("el jugador ", jugador, "entra a la cola Rapida")
        tiempo3 = datetime.datetime.now().strftime("%H:%M:%S")
        semaforo_logs.release()

        #Entra a la partida y sale de la cola
        semaforo_rapida.acquire()
        cola_rapida.release()

        semaforo_logs.acquire()
        f = open("PartidaRapida.txt", 'a')
        tiempo4 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo3 + ", " + tiempo4 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()


        semaforo_logs.acquire()
        print("jugador", jugador, "esperando a que comience la partida")
        semaforo_logs.release()
        #Esperando a tener suficientes jugadores
        try:
            barrier_rapida.wait()
        except threading.BrokenBarrierError:
            barrier_rapida.reset()
        #Comienza la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " entra la partida rapida")
        semaforo_logs.release()
        time.sleep(6)
        #Termina la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " sale de la partida rapida")
        semaforo_logs.release()
        try:
            barrier_rapida_salida.wait()
        except threading.BrokenBarrierError:
            barrier_rapida_salida.reset()

        semaforo_logs.acquire()
        f = open("Salida.txt", 'a')
        tiempo5 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo5 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_rapida.release()

    elif sala == 3:     # Partida especial de Navidad
        cola_rapida.acquire()
        semaforo_logs.acquire()
        f = open("Lobby.txt", 'a')
        tiempo2 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo1 + ", " + "Partida Especial de Navidad, " + tiempo2 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_logs.acquire()
        print("el jugador ", jugador, "entra a la cola Especial de Navidad")
        tiempo3 = datetime.datetime.now().strftime("%H:%M:%S")
        semaforo_logs.release()

        #Entra a la partida y sale de la cola
        semaforo_navidad.acquire()
        cola_navidad.release()

        semaforo_logs.acquire()
        f = open("PartidaEspecialNavidad.txt", 'a')
        tiempo4 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo3 + ", " + tiempo4 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()


        semaforo_logs.acquire()
        print("jugador", jugador, "esperando a que comience la partida")
        semaforo_logs.release()
        #Esperando a tener suficientes jugadores
        try:
            barrier_navidad.wait()
        except threading.BrokenBarrierError:
            barrier_navidad.reset()
        #Comienza la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " entra la partida de navidad")
        semaforo_logs.release()
        time.sleep(5)
        #Termina la partida
        semaforo_logs.acquire()
        print("el jugador", jugador, " sale de la partida de navidad")
        semaforo_logs.release()
        try:
            barrier_navidad_salida.wait()
        except threading.BrokenBarrierError:
            barrier_navidad_salida.reset()

        semaforo_logs.acquire()
        f = open("Salida.txt", 'a')
        tiempo5 = datetime.datetime.now().strftime("%H:%M:%S")
        buffer = "Jugador" + str(jugador) + ", " + tiempo5 + "\n"
        f.write(buffer)
        f.close()
        semaforo_logs.release()

        semaforo_navidad.release()




n_jugadores = 120

thread_jugadores = []
for j in range(n_jugadores):
    num_sala = random.randint(0, 3)
    tj = threading.Thread(target=juego, args=([j + 1], num_sala), daemon=True)
    thread_jugadores.append(tj)
    tj.start()
    time.sleep(0.3)


for t in thread_jugadores:
    t.join()