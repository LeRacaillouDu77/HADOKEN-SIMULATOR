<h1 align="center">🔥 HADOKEN SIMULATOR 🔥</h1>

<p align="center">
  <strong>Un mini-jeu développé en C avec CSFML — inspiré de My_Hunter (Epitech)</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue">
  <img src="https://img.shields.io/badge/Library-CSFML-orange">
  <img src="https://img.shields.io/badge/Status-Work%20in%20Progress-yellow">
  <img src="https://img.shields.io/badge/Platform-PC-lightgrey">
</p>

---

## 🎮 Présentation

**Hadoken Simulator** est un jeu développé en **C**, utilisant la bibliothèque **CSFML**.  
Il revisite le concept du projet *My_Hunter* d’Epitech avec un style rétro arcade.

Le but : **réagir rapidement**, lancer des *Hadoken* et interagir avec les éléments à l’écran.

---

## 🛠️ Technologies utilisées

| Technologie | Description |
|------------|-------------|
| **C** | Langage principal |
| **CSFML** | Bibliothèque multimédia |
| **GCC / Make** | Outils de compilation |
| **VSCode** | IDE conseillé |

---

## 📂 Structure du projet

HADOKEN-SIMULATOR/
├── CSFML-2.5.1-sources/ # Sources de CSFML
├── source/ # Code du jeu
│ ├── main.c
│ ├── ...
| ├── assets/
└── README.md

---

## 🚀 Installation & Lancement

### 1️⃣ Installer CSFML  
(Déjà incluse dans le repo, sinon télécharger via SFML.)

```bash
cd CSFML-2.5.1-sources
cmake .
make
sudo make install
```

2️⃣ Compiler le jeu
Depuis la racine ou le dossier source :

bash
Copy code
gcc -o hadoken_simulator source/main.c -lcsfml-graphics -lcsfml-window -lcsfml-system
(ajoute d’autres .c si nécessaire)

3️⃣ Lancer le jeu
```bash
./hadoken_simulator
```

🧩 Fonctionnalités

Fenêtre de jeu fonctionnelle

Gestion des événements clavier/souris

Affichage d’éléments graphiques

Mode Expert avec plusieurs difficultés

Système de score

Menu principal/expert interactif

Musique et effets sonores

MIT License  
Copyright (c) 2025 LeRacaillouDu77
👤 Auteur
LeRacaillouDu77
🔗 GitHub : https://github.com/LeRacaillouDu77

<p align="center"> ✨ *Hadoken Simulator ✨ </p> ```
