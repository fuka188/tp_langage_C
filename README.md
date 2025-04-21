# tp_langage_C
tp langage C KAZMIERCZAK Florian 1 ère année licence mathématique



# 📊 Projet C — Application d'entraînement aux opérations arithmétiques

## 📝 Description du projet

Ce projet a été réalisé dans le cadre du module de programmation en langage C.  
Il s'agit d'une application console interactive qui permet à un utilisateur de s’exercer aux opérations arithmétiques de base :  

- Addition  
- Soustraction  
- Multiplication  
- Division entière  
- Calcul du carré d’un entier  
- Révision des tables de multiplication  

Le programme attribue un score en fonction du nombre de tentatives pour chaque réponse et **sauvegarde automatiquement le score dans un fichier texte (`scores.txt`) en fonction du nom du joueur.  

L’utilisateur peut ainsi retrouver son score à chaque exécution.

## ⚙️ Instructions d’installation et d’utilisation
- aucune installation n'est requise.. Il faut juste un compilateur C
- 
### 🔧 Compilation

Vous pouvez compiler le projet avec GCC :

```bash
gcc -o arithmetique tp_langage_c_daoud.c
```

### ▶️ Exécution

Une fois compilé, exécutez le programme dans un terminal :

```bash
./arithmetique
```

### 📚 Fonctionnement

1. Le programme vous demande votre nom.  
2. Il vérifie si un score est déjà enregistré pour vous.  
3. Il affiche un menu avec les opérations disponibles.  
4. Vous choisissez une activité, et le programme vous pose des questions.  
5. Votre score est mis à jour après chaque bonne réponse, en fonction du nombre d’essais.  
6. À la fin de votre session, votre score est sauvegardé.

## ✅ Pré-requis

- Système d’exploitation : Linux, macOS ou Windows (via Code::Blocks ou terminal)
- Compilateur C (GCC recommandé)
- Environnement compatible avec les programmes console
- Notions de base en ligne de commande

## 🛠️ Outils utilisés

- Langage C— ISO C99 standard  
- Code::Blocks — IDE pour le développement et les tests  
- GCC — Compilateur pour la compilation locale  
- Fichiers texte — Pour la sauvegarde des scores (`scores.txt`)  



