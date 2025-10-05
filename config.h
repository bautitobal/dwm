/* Bauti Tobal's dwm config
 * Hyprland-style keybinds
 * Nord x Detective Conan theme
 */

/* appearance */
static const unsigned int borderpx  = 2;  /* default: 1; border pixel of windows */
static const unsigned int snap      = 32; /* snap pixel */

/* gaps */
// default: 10, 10, 10, 10, 1
static const unsigned int gappih    = 8;  /* horizontal inner gap between windows */
static const unsigned int gappiv    = 8;  /* vertical inner gap between windows */
static const unsigned int gappoh    = 10;  /* horizontal outer gap between windows and screen edge */
static const unsigned int gappov    = 10;  /* vertical outer gap between windows and screen edge */
static const int smartgaps          = 1;   /* 1 means no outer gap when only one window */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=14" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=11";

// Colors
/*static const char col_gray1[]       = "#2E3440";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
*/
/*
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
*/
static const char col_bg[]          = "#2E3440"; // dark nord blue-gray
static const char col_fg[]          = "#D8DEE9"; // nord white
static const char col_blue[]        = "#81A1C1"; // nord light blue
static const char col_cyan[]        = "#88C0D0"; // cyan accent
static const char col_red[]         = "#BF616A"; // red accent (Conan touch)
static const char col_border[]      = "#3B4252"; // darker border
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_fg, col_bg, col_border },
	[SchemeSel]  = { col_blue, col_bg, col_blue  },
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#include <X11/XF86keysym.h>
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */

// Apps and scripts
// static const char *dmenucmd[]   = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = {
    "dmenu_run", "-m", dmenumon, "-fn", dmenufont,
    "-nb", col_bg,     /* background color */
    "-nf", col_fg,     /* normal foreground */
    "-sb", col_blue,   /* selected background */
    "-sf", col_cyan,   /* selected foreground */
    NULL
};
static const char *termcmd[]     = { "kitty", NULL };
static const char *rofi[]        = { "rofi", "-show", "drun", "-theme", "~/.config/rofi/config.rasi", NULL};
static const char *fmanager[]    = { "thunar", NULL };
static const char *browser[]     = { "brave", NULL };
static const char *altBrowser[]  = { "librewolf", NULL };
static const char *printscrcmd[] = { "flameshot", "gui", NULL };
static const char *lockcmd[]     = { "slock", NULL };
static const char *zenmode[]     = { "~/dotfiles/scripts/zen-mode.sh", NULL };

#include "movestack.c"
// Keybindings
static const Key keys[] = {
	/* modifier                     key        function        argument */

  // Apps
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
  { MODKEY,                       XK_d,      spawn,          {.v = rofi } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
  { MODKEY,                       XK_b,      spawn,          {.v = browser } },
  { MODKEY|ShiftMask,             XK_b,      spawn,          {.v = altBrowser } },
  { MODKEY,                       XK_e,      spawn,          {.v = fmanager } },
  { 0,                            XK_Print,  spawn,          {.v = printscrcmd } },
  { MODKEY|ControlMask|ShiftMask, XK_l,      spawn,          {.v = lockcmd } },
  { MODKEY|ShiftMask,             XK_z,      spawn,          {.v = zenmode } },

  // Window management
	{ MODKEY,                       XK_q,      killclient,     {0} },
  { MODKEY|ShiftMask,             XK_m,      quit,           {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
  { MODKEY,                       XK_f,      togglefullscr,     {0} },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
  
  // Focus navigation (vim-like)
  { MODKEY,                       XK_h,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_l,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

  // Move window position in stack
  { MODKEY|ShiftMask,             XK_h,      movestack,      {.i = -1 } },
  { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
  { MODKEY|ShiftMask,             XK_l,      movestack,      {.i = +1 } },

  // Resize area
  { MODKEY|ControlMask,           XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY|ControlMask,           XK_l,      setmfact,       {.f = +0.05} },

  // Gaps control
  { MODKEY|ShiftMask,             XK_g,      togglegaps,     {0} },
  { MODKEY|ControlMask,           XK_g,      defaultgaps,    {0} },

  // Multimedia
  { 0, XF86XK_AudioRaiseVolume,   spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+") },
	{ 0, XF86XK_AudioLowerVolume,   spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-") },
	{ 0, XF86XK_AudioMute,          spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle") },
	{ 0, XF86XK_MonBrightnessUp,    spawn, SHCMD("brightnessctl s 10%+") },
	{ 0, XF86XK_MonBrightnessDown,  spawn, SHCMD("brightnessctl s 10%-") },
	{ 0, XF86XK_AudioNext,          spawn, SHCMD("playerctl next") },
	{ 0, XF86XK_AudioPrev,          spawn, SHCMD("playerctl previous") },
	{ 0, XF86XK_AudioPlay,          spawn, SHCMD("playerctl play-pause") },

  // defaults (some are by default dwm conf)
	{ MODKEY|ShiftMask,             XK_x,      togglebar,      {0} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_z,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

