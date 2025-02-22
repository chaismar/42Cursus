# Classe Client

## Attributs
- **int _socket_client**
  - valeur du socket client qui permet d'envoyer un message a un client correspond au fd d'un fichier
- **std::string _nickname :**
  - nom choisi avec la commande NICK
  - Longueur maximale : 9 caractères
  - Attention aux doublons (convention : `{}` | `[]\` à comprendre)
  - caractere interdit `' '` , `','` , `'*'` , `'?'` , `'!'` , `'@'`, `'.'` ,
  - caractere interdit au debut `'$'` , `':'` `'#'` , `'&'`, `'~'`, `'%'`, `'+'`

- **std::string _username :**
  - nom utilise sur la session

- **std::string _adress :**
  - addresse ip utilisee pour la connexion
- **std::string _nickmask :**
  - combinaison nick!user@host

<sub> *(peut etre une class operator qui herite de Client et qui possede toutes ces fonctions idk)* </sub>

- **int _role :**
  - Détermine les droits de l'utilisateur.
  - Accès aux commandes pour les modérateurs :
    - `KICK` : Éjecter un client d'un canal.
    - `INVITE` : Inviter un client dans un canal.
    - `TOPIC` : Changer le sujet d'un canal.
    - `MODE` : Changer le mode du canal.
      - `-i` : Définir et supprimer le canal.
      - `-t` : Définir et supprimer les droits de la commande Topic pour les autres Clients.
      - `-k` : Définir et supprimer la clé du Channel (mot de passe).
      - `-o` : Donner et supprimer le privilège d'opérateur de canal.
      - `-l` : Définir et supprimer une limite de Clients sur un Channel.

## Fonctions membres

- Possibilité d'envoyer des messages privés.
---

# Classe Channel
  - **lister les modes de channel a implemente**
  - local channel (`&`)
  - Contient l'ensemble des Clients dans le canal.
  - Détruit lorsque le dernier Client quitte.
  - premier client qui rejoint est automatiquement operator
## Attributs
- **List de Client :**
  - liste des clients dans le channel
- **_topic :**
  - Sujet du canal.
  - Longueur maximale : 200 caractères.
  - Doit commencer par `&`
  - Pas `' '` , de `','` , ou de `'^G'` (retour a la ligne)
  - Ne doit pas commencer par `#`

- **_password :**
  - Mot de passe pour accéder au canal.

- **_max_connected :**
  - Nombre maximum d'utilisateurs connectés.
  - Créé automatiquement lors de la connexion d'un Client ou avec le code `JOIN`.

## Fonction membres

- envoie de message a tout les Clients de Channel
- Ajouter un nouveau Client dans le Channel
- Kick un Client dans le Channel
- toutes les commandes operateurs

---
# Class Server
  - initialisation du socket listen a la construction



# Regles

## Messages :
- PASS
- NICK
- USER
- PING
  -> PONG par extension
- PART
- QUIT
- JOIN
- PRIVMESSAGE
- TOPIC
- KICK
- MODE
- INVITE
- CAP

---
1. Tout les message sont forme sous cette forme : 
- prefix (optionel)
- la commande
- les parametres
2. Les parametres sont separes par un ou plusieurs espace seulement `' '` et rien d'autre
3. la presence d'un prefix est signale par le char `':'` en premiere position dans le message
	- permet d'indique qui est l'auteur d'un message d'origine
	- si une erreur est detecter ave un prefix le message est ignore
4. les commandes doivent etre une commande valide de IRC ou un 3 ?????
5. Les messages sont toujours envoyes avec un retour chariot
6. La taille max d'un message est de 510 char (510 + retour chariot)
