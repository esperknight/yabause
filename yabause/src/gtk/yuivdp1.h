#ifndef YUI_VDP1_H
#define YUI_VDP1_H

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtktable.h>

#include "yuiwindow.h"

G_BEGIN_DECLS

#define YUI_VDP1_TYPE            (yui_vdp1_get_type ())
#define YUI_VDP1(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), YUI_VDP1_TYPE, YuiVdp1))
#define YUI_VDP1_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  YUI_VDP1_TYPE, YuiVdp1Class))
#define IS_YUI_VDP1(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), YUI_VDP1_TYPE))
#define IS_YUI_VDP1_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  YUI_VDP1_TYPE))

#define MAX_VDP1_COMMAND 4000

typedef struct _YuiVdp1       YuiVdp1;
typedef struct _YuiVdp1Class  YuiVdp1Class;

struct _YuiVdp1
{
  GtkWindow dialog;

  GtkWidget * vbox;
  GtkWidget * hbox;
  GtkWidget * commName;
  GtkWidget * commDesc;
  GtkWidget * spin;
  GtkWidget * buttonVBlankOut;

  GtkListStore * store;
  GtkWidget * view;
  GtkTextBuffer * buffer;

  gint cursor;
};

struct _YuiVdp1Class
{
  GtkWindowClass parent_class;

  void (* yui_vdp1) (YuiVdp1 * yv);
};

GType		yui_vdp1_get_type       (void);
GtkWidget *	yui_vdp1_new            (YuiWindow * yui);
void		yui_vdp1_fill		(YuiVdp1 * vdp1);
void		yui_vdp1_update		(YuiVdp1 * vdp1);
void		yui_vdp1_destroy	(YuiVdp1 * vdp1);

G_END_DECLS

#endif