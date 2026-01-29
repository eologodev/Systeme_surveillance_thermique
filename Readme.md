Système de Surveillance Thermique et Ventilation

    Projet : Contrôle de température industriel avec filtrage et hystérésis.

1. Présentation

Ce projet implémente un système de régulation automatique d'un ventilateur basé sur les lectures d'un capteur de température. L'objectif est de garantir une activation stable du matériel malgré les parasites de mesure.
2. Fonctionnalités Clés

    Filtrage des Parasites : Les valeurs aberrantes (>80 °C) sont automatiquement ignorées pour éviter les déclenchements accidentels.

    Lissage par Moyenne Mobile : Utilisation d'un buffer circulaire de 10 échantillons pour stabiliser les mesures.

    Régulation par Hystérésis : * Seuil d'activation : 35 °C

        Seuil d'arrêt : 30 °C (Seuil−5 °C)

    Architecture Modulaire : Séparation du code en couches (Sensor, Buffer, Ventilation).

3. Schéma de Branchement

    Capteur : Connecté au Pin Analogique/Digital (selon ton montage).

    Actionneur (Ventilateur/LED) : Connecté au Pin 13.

    Console : Communication Série à 115200 Baud.

4. Structure du Projet

    sketch.ino : Point d'entrée et boucle principale (C++).

    buffer.c / .h : Gestion de la mémoire et du calcul de la moyenne.

    sensor.c / .h : Acquisition et filtrage des données brutes.

    ventilation.c / .h : Logique de décision et contrôle de l'actionneur (C standard).

5. Exemple de Fonctionnement
Mesure Brute: 36.59 | Lissee: 35.12 -> [ALERTE] VENTILATION ALLUMEE
Mesure Brute: 32.09 | Lissee: 35.01 -> (Reste allumée : Hystérésis)
Mesure Brute: 23.09 | Lissee: 29.84 -> [INFO] VENTILATION ETEINTE
