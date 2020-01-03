# Learn C using VS Code
Download and setup instructions plus some links to online courses

### Prerequisiti
Per utilizzare VS Code come ambiente di sviluppo per studiare il linguaggio C occorre prima di tutto:
1. Installare Visual Studio Code.
2. Installare l'estensione C/C++ per VS Code.
3. Scaricare il compilatore Mingw-w64 da Sourceforge e avviare l'installazione, impostando "Architecture" a "x86_64" e "Threads" a "win32":

    ![image](https://user-images.githubusercontent.com/139274/71647348-d166b400-2cf5-11ea-8310-ff15fcd6459b.png)

    Nella scelta della cartella di installazione è essenziale utilizzare un percorso che non abbia spazi al suo interno (in altre parole, NON nella cartella "C:/Program Files/"). Nel nostro caso, abbiamo utilizzato la cartella "C:\Mingw-w64\":

    ![image](https://user-images.githubusercontent.com/139274/71647367-29051f80-2cf6-11ea-9904-76e2d3ab719a.png)

4. 	Aggiungere il percorso della cartella "bin" di Mingw-w64 alla variabile di ambiente di Windows "PATH":

    a) Aprire la modifica delle variabili d'ambiente per l'account digitando "variabili" dallo Start menu:
    
    ![image](https://user-images.githubusercontent.com/139274/71647369-328e8780-2cf6-11ea-96d4-dfeefe35e47b.png)
    
    b) Selezionare "Path" e cliccare su "Modifica, poi cliccare su "Nuovo" e inserire "C:\Mingw-w64\bin" (da modificare in relazione alla cartella di installazione scelta):
    
    ![image](https://user-images.githubusercontent.com/139274/71647402-cfe9bb80-2cf6-11ea-86a5-906eb4300ba9.png)
    
    Selezionare infine OK per salvare le modifiche effettuate. Sarà necessario riaprire ogni finestra Console affinché il nuovo path sia disponibile.
    
### Creare l'ambiente di lavoro in VS Code
Per usufruire delle funzionalità di Intellisense e poter eseguire e fare il debugging di un programma in VS Code, è indispensabile definire le proprietà del progetto, il task di compilazione e le operazioni di lancio.
Di solito tali file vengono creati in una cartella ".vscode" che si trova nella cartella di progetto che contiene il programma. Così facendo però, per ogni nuovo programma occorre replicare questi file e modificare i comandi per compilare e lanciare quello specifico programma. Per evitare questa "seccatura", è possibile utilizzare un'unica cartella ".vscode" posta in una cartella che contiene i diversi programmi. Di seguito un'illustrazione che mostra le due diverse ipotesi, standard e ottimizzata:

![image](https://user-images.githubusercontent.com/139274/71647920-51444c80-2cfd-11ea-8361-2af130d2e085.png)

Per la versione ottimizzata, bisogna utilizzare le variabili che possono essere usate all'interno delle stringhe, in modo da ottenere dei comandi che si adattano automaticamente al nome del file attivo al momento dell'esecuzione del comando di compilazione e debugging:

#### File "tasks.json":

```
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "build active file with MinGW",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "command": "gcc",
            "args": [
                "-Wall",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}"
            ]
        }
    ]
}
```

#### File "launch.json":

```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "gcc.exe build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\Mingw-w64\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build active file with MinGW"
        }
    ]
}
```

#### File "c_cpp_properties.json":

```
{
    "version": 4,
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:/Mingw-w64/mingw64/bin/gcc.exe",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ]
}
```
Ulteriori informazioni su come usare VS Code per fare il debugging si possono trovare nella [documentazione ufficiale](https://code.visualstudio.com/docs/cpp/config-mingw#_start-a-debugging-session).

### Learning links

[C Tutorial](https://www.tutorialspoint.com/cprogramming/index.htm)
