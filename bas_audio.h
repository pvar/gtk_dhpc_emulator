/*
 * Implementation of audio related commands of nstBASIC.
 *
 * Copyright 2016, Panagiotis Varelas <varelaspanos@gmail.com>
 *
 * nstBASIC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * nstBASIC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/gpl-3.0.html>.
 */

#ifndef BAS_AUDIO_H
#define BAS_AUDIO_H

#include <stdio.h>
#include <stdlib.h>
#include "cpu_interpreter.h"
#include "cpu_parser.h"

guchar snd_play (void);
guchar snd_stop (void);
guchar snd_tempo (void);
guchar snd_music (void);

#endif
