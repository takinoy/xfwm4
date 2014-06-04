/*      $Id$

        This program is free software; you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation; either version 2, or (at your option)
        any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program; if not, write to the Free Software
        Foundation, Inc., Inc., 51 Franklin Street, Fifth Floor, Boston,
        MA 02110-1301, USA.


        oroborus - (c) 2001 Ken Lynch
        xfwm4    - (c) 2002-2011 Olivier Fourdan

 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <glib.h>
#include "screen.h"

#ifdef HAVE_RENDER
#include <X11/extensions/Xrender.h>
#endif

#ifndef INC_MYPIXMAP_H
#define INC_MYPIXMAP_H

#define MYPIXMAP_XPIXMAP(p) (p.pixmap)

#define XFWM_PIXMAP_FLIP_NONE                     (1L << 0)
#define XFWM_PIXMAP_FLIP_HORIZONTAL               (1L << 1)
#define XFWM_PIXMAP_FLIP_VERTICAL                 (1L << 2)

typedef struct
{
    gchar *name;
    const gchar *value;
}
xfwmColorSymbol;

struct _xfwmPixmap
{
    ScreenInfo *screen_info;
    Pixmap pixmap, mask;
#ifdef HAVE_RENDER
    XRenderPictFormat *pict_format;
    Picture pict;
#endif
    gint width, height;
};

gboolean                 xfwmPixmapRenderGdkPixbuf              (xfwmPixmap *,
                                                                 GdkPixbuf *);
GdkPixbuf *              xfwmPixbufLoad                         (const gchar *,
                                                                  const gchar *,
                                                                  xfwmColorSymbol *);
gboolean                 xfwmPixmapLoad                         (ScreenInfo *,
                                                                 xfwmPixmap *,
                                                                 const gchar *,
                                                                 const gchar *,
                                                                 xfwmColorSymbol *);
gboolean                 xfwmPixmapLoadSplit                        (ScreenInfo * screen_info,
                                                                 xfwmPixmap * pmA, int h,
                                                                 xfwmPixmap * pmB, const
                                                                 gchar * dir, const gchar *
                                                                 file, xfwmColorSymbol * cs);
void                     xfwmPixmapCreate                       (ScreenInfo *,
                                                                 xfwmPixmap *,
                                                                 gint,
                                                                 gint);
void                     xfwmPixmapInit                         (ScreenInfo *,
                                                                 xfwmPixmap *);
void                     xfwmPixmapFree                         (xfwmPixmap *);
gboolean                 xfwmPixmapNone                         (xfwmPixmap *);
void                     xfwmPixmapFill                         (xfwmPixmap *,
                                                                 xfwmPixmap *,
                                                                 gint,
                                                                 gint,
                                                                 gint,
                                                                 gint);
void                     xfwmPixmapDuplicate                    (xfwmPixmap *,
                                                                 xfwmPixmap *);
#endif /* INC_MYPIXMAP_H */
