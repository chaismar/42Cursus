# Pipex

## Description

Pipex est un projet de l'école 42 qui consiste à reproduire le comportement du pipe (`|`) en shell. Le programme doit rediriger la sortie d'une commande vers l'entrée d'une autre commande, en utilisant des appels système Unix.

## Objectifs

- Comprendre et utiliser les pipes dans les systèmes Unix.
- Gérer plusieurs processus et descripteurs de fichiers.
- Utiliser les appels système `pipe()`, `fork()`, `dup2()` et `execve()`.

## Utilisation

Pour exécuter le programme, utilisez la commande suivante :
```sh
./pipex fichier1 cmd1 cmd2 fichier2
```
Où :
- `fichier1` est le fichier d'entrée.
- `cmd1` est la première commande à exécuter.
- `cmd2` est la deuxième commande à exécuter.
- `fichier2` est le fichier de sortie.

## Exemple

```sh
./pipex infile "ls -l" "grep pipex" outfile
```

Cela exécutera `ls -l` sur `infile`, puis passera la sortie à `grep pipex`, et écrira le résultat dans `outfile`.
## Bonus

En plus des fonctionnalités de base, le projet Pipex inclut les bonus suivants :

- **Gestion des commandes multiples** : Le programme peut gérer plus de deux commandes en chaîne, redirigeant la sortie de chaque commande vers l'entrée de la suivante.
- **Support des guillemets** : Le programme peut interpréter correctement les commandes entourées de guillemets simples ou doubles, permettant l'utilisation de commandes complexes avec des arguments contenant des espaces.
- **Gestion des erreurs améliorée** : Le programme fournit des messages d'erreur plus détaillés et gère les erreurs de manière plus robuste, y compris les erreurs de fichier et les erreurs de commande.
- **Support des redirections** : Le programme peut gérer les redirections supplémentaires, telles que la redirection de l'entrée standard (`<`) et de la sortie standard (`>`).

### Exemple de commande multiple

```sh
./pipex infile "cat -e" "grep pipex" "wc -l" outfile
```

Cela exécutera `cat -e` sur `infile`, puis passera la sortie à `grep pipex`, ensuite à `wc -l`, et écrira le résultat dans `outfile`.

### Exemple avec guillemets

```sh
./pipex infile "echo 'Hello World'" "tr ' ' '_'" outfile
```

Cela exécutera `echo 'Hello World'` sur `infile`, puis passera la sortie à `tr ' ' '_'`, et écrira le résultat dans `outfile`.

### Gestion des erreurs

Le programme affichera des messages d'erreur détaillés si une commande échoue ou si un fichier ne peut pas être ouvert.

### Redirections supplémentaires

Le programme peut également gérer des redirections supplémentaires comme suit :

```sh
./pipex < infile cmd1 cmd2 > outfile
```

Cela redirigera l'entrée standard depuis `infile`, exécutera `cmd1` et `cmd2`, puis redirigera la sortie standard vers `outfile`.

## Commentaires

![Pipex Project](Images/image.png)