# Universidad EAFIT
# Curso ST0263 Tópicos Especiales en Telemática, 2018-2
# Profesor: Edwin Montoya M. – emontoya@eafit.edu.co
# Laboratorio de MPI

# entrar al cluster:

## conectar a la VPN

        $ ssh user-vpn@192.168.10.80
        Password: pass-vpn

## instalar las claves ssh para cada usuario (solo se hace una vez):

// conectar a master:

        $ ssh user-vpn@192.168.10.80
        Password: pass-vpn
        $ mkdir ~/.ssh
        $ ssh-keygen -t rsa -b 4096 -C "your_username@eafit.edu.co"
        // de enter a todas las opciones
        $
        $ cd .ssh
        $ cp id_rsa.pub authorized_keys
        $ scp ~/.ssh/id_rsa ~/.ssh/id_rsa.pub user-vpn@192.168.10.81:
        Password: pass-vpn
        $ scp ~/.ssh/id_rsa ~/.ssh/id_rsa.pub user-vpn@192.168.10.82:
        Password: pass-vpn

// conectar a slave1:

        $ ssh user-vpn@192.168.10.81
        Password: pass-vpn        
        $ mkdir ~/.ssh
        $ cp ~/id_rsa ~/id_rsa.pub ~/.ssh
        $ cd ~/.ssh
        $ cp id_rsa.pub authorized_keys
        $ exit

// conectar a slave2:

        $ ssh user-vpn@192.168.10.82
        Password: pass-vpn        
        $ mkdir ~/.ssh
        $ cp ~/id_rsa ~/id_rsa.pub ~/.ssh
        $ cd ~/.ssh
        $ cp id_rsa.pub authorized_keys
        $ exit
