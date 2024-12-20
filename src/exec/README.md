exec:       1) fetch closest wall using the longest x/y step.
            2) determine if it is a N/E/S/O wall by checking the player's camera angle on the circle radius
            3) find height of wall
            4) Draw on image the wall from top pixel to bottom for the given ray
            5) based on the wall delimiters, draw on image the floor and ceilling for the given ray
            6) Repeat for each ray on the screen by incrementing the angle (based on FOV)
            7) send image to window once the rays have covered the entire screen

key hooks:  1) if the player wants to move left/right/forwards/backwards by using q/f/z/s 113/100/122/115
