# Projet TP 

A multimedia management application combining C++ backend with Java Swing GUI, demonstrating object-oriented programming principles including inheritance, polymorphism, and memory management.

## Project Overview

This project implements a multimedia management system with support for:
- **Photos** - with geographic location metadata (latitude/longitude)
- **Videos** - with duration tracking
- **Films** - videos with chapter information
- **Groups** - collections for organizing multimedia items
- **Client-Server Architecture** - TCP-based communication between client and server

## Project Structure

```
├── cpp/                    # C++ Backend Implementation
│   ├── multimedia.h/cpp    # Abstract base class for all multimedia types
│   ├── photo.h/cpp         # Photo class with location support
│   ├── video.h/cpp         # Video class with duration
│   ├── film.h/cpp          # Film class extending Video with chapters
│   ├── group.h/cpp         # Container for multimedia collections
│   ├── manager.h/cpp       # Factory and manager for multimedia objects
│   ├── tcpserver.h/cpp     # TCP server for client communication
│   ├── ccsocket.h/cpp      # Socket communication utilities
│   ├── exceptions.h        # Custom exception definitions
│   ├── main.cpp            # Server entry point
│   ├── Makefile            # Build configuration
│   └── TP1                 # Compiled executable
│
├── swing/                  # Java Swing GUI
│   ├── Client.java         # TCP client for server communication
│   ├── ClientGUI.java      # Graphical interface with search/play controls
│   ├── Mainwindow.java     # Alternative window interface
│   └── Makefile            # Java build configuration
│
├── Doxyfile                # Doxygen configuration for documentation generation
└── README.txt              # This file

```

## Prerequisites
- g++
- make
- Java Development Kit (JDK) for GUI compilation
- Doxygen (optional, for generating HTML documentation)

## Compilation
1. Ouvrez un terminal dans le dossier du projet.
2. Pour le backend C++ : `cd cpp/ && make`
3. Pour la GUI Java : `cd swing/ && make`
4. Utilisez `make run` pour compiler et exécuter le projet en une seule commande.

### Details of Compilation

**C++ Backend:**
```bash
cd cpp/
make                  # Compile the server
make run              # Compile and run the server
make clean            # Clean build artifacts
```

**Java Swing GUI:**
```bash
cd swing/
make                  # Compile the GUI
java ClientGUI        # Run the GUI client
java Mainwindow       # Run alternative interface
make clean            # Clean build artifacts
```

## Exécution

**Server (C++ Backend):**
1. Lancez : `cd cpp/ && ./TP1`
   - Server listens on port 3331

**Client (Java GUI):**
2. Lancez : `cd swing/ && java ClientGUI`
   - Connects to localhost:3331
   - Provides search and play functionality

## Nettoyage
- C++ cleanup: `cd cpp/ && make clean`
- Java cleanup: `cd swing/ && make clean`

## Key Features

### C++ Backend
- **Object-Oriented Design**: Inheritance hierarchy with abstract Multimedia base class
- **Polymorphism**: Virtual methods for display, play, and write operations
- **Memory Management**: Smart pointers (std::shared_ptr) for automatic cleanup
- **TCP Server**: Listens for client requests and processes multimedia operations
- **Factory Pattern**: Manager class creates and manages all multimedia objects
- **Serialization**: Multimedia data can be written to and read from files

### Java GUI
- **Swing Framework**: Clean, responsive graphical interface
- **Event Handling**: Button actions and menu item responses
- **Client-Server Communication**: TCP sockets for server interaction
- **Intuitive Controls**: Search, play, and exit functionality

## Documentation

API documentation is included in each header file with Doxygen-compatible comments.
To generate HTML documentation:
```bash
doxygen Doxyfile
```
This creates documentation in the `html/` directory.

---

## Réponses aux Questions du Projet

1. Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?
il s'appelle méthode abstraite. Il faut le declarer avec le mot-clé virtual et sans implémentation.

2. Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?
Parce que la classe Multimedia a au moins une méthode abstraite, et il ne sera plus d'être instanciée.

3. Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
Polymorphism. Tout les sous-classes hériteront des méthodes et sont traités de la même manière.

4. Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? 
Il faut des méthodes virtuelles pour override la classe de base.

5. Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java. 
Des éléments du tableau sont des pointeurs aux instances de la classe de base. 
Le tableau doit contenir des pointeurs parce qu‘il est nécessaire de garder l'addresse de tous les objets pour les accéder.
Par contre, en Java, le valeur du pointeur est caché. 

6. Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?
La classe Film

7. Quel est le problème et quelles sont les solutions ?
Si une classe possède une instance qui est un pointeur, lors de la copie d'un objet d'une instance,
seul l'addresse du objet est copiée, et non pas son contenu.
Quand le destructeur du premier objet libère cette memoire, l'autre objet deviendra un pointeur pendant.

Donc il faut faire une copie des éléments du tableau eux-même dans le contructeur.

8. On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
Parce que la polymorphism n'est que possible en creant une liste de pointeurs. Si on a une liste d'objets,
ils doivent avoir le même type.

9. Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ? 
On peut mettre les contructeurs dans protected ou private, et après en utilisant le mot clé friend,
on donne l'accès seulement à une classe pour les manipuler.