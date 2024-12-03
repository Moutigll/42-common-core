/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:26:11 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/03 09:33:45 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
    void *mlx;
    void *win;

    // Initialisation de la bibliothèque mlx
    mlx = mlx_init();
    
    // Création d'une fenêtre de 800x800 pixels
    win = mlx_new_window(mlx, 800, 800, "Pixel Example");

    // Affichage d'un pixel rouge (0xFF0000) à la position (400, 400)
    mlx_pixel_put(mlx, win, 400, 400, 0xFF0000);

    // Boucle infinie pour maintenir la fenêtre ouverte
    mlx_loop(mlx);

    return (0);
}
