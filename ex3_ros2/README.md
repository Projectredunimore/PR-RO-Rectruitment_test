## Esercizio 3 — Utilizzo di ROS2

ROS2 è il framework di robotica che utilizziamo per controllare il rover, per completare questo esercizio è necessario installare **ROS2 Jazzy**.

### Installazione ROS2

Per l'installazione di ROS2 è necessario avere un sistema operativo **Ubuntu 24.04**, puoi seguire [questo tutorial](https://www.youtube.com/watch?v=qq-7X8zLP7g) su come installare linux insieme a windows sul proprio PC (il download dell'iso in descrizione non funziona, usa [questo](https://releases.ubuntu.com/noble/ubuntu-24.04.5.1-desktop-amd64.iso)) . Alternativamente è possibile utilizzare **WSL2** che è la macchina virtuale linux ufficiale di windows.

### Esercizio

L'esercizio consiste nell'utilizzare i dati del sensore implementato nell'esercizio 2 all'interno di ROS2, anche in questo caso l'esercizio è libero e puoi scegliere a tuo piacimento lo svolgimento. Ecco come potrebbero essere utilizzati gli esempi forniti nell'esercizio 2 per lo svolgimento di questo esercizio:

 - **A: Implementazione di una telecamera:** Leggere dati da una webcam, pubblicarli su un topic di ros così che possa essere utilizzato da altri nodi, sottoscrivere a diversi topic che permettono di cambiare parametri della telecamera, come risoluzione, luminosità, ...

 - **B: Teleoperazione tramite tastiera o joystick:** Utilizzare una periferica per comandare un robot mobile, implementando i comandi di velocità su 3 assi (x, y, rotazione), i comandi vengono pubblicati su un topic e utilizzati da un altro nodo che calcola un profilo di accelerazione per raggiungere la velocità indicata in maniera fluida, infine ripubblica i valori di velocità da inviare ai motori.

 - **C: Rotazione di un gimball tramite mouse:** Utilizzare il proprio mouse per ottenere comandi di posizione dei 2 assi (roll, pitch) del gimball, il comando viene pubblicato su un topic e utilizzato da un nodo che tramite un controllore PID calcola i comandi di velocità da inviare ai motori (per la chiusura dell'anello in retroazione si possono assumere motori ideali, cioè che tra un comando di velocità e l'altro avranno percorso esattamente `dt * vel_cmd`).

Al termine dell'esercizio si crei un piccolo video dimostrativo del funzionamento (circa 15 secondi) e lo si alleghi all'interno di questa cartella.

### Suggerimenti

- Per visualizzare immagini sui topic di ros è possibile utilizzare il tool `rqt_image_view`.
- L'esercizion indicato nell'esempio B è simile a [questo pacchetto](https://index.ros.org/r/teleop_twist_keyboard/).
