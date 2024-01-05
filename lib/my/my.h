/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** h file do prototype
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <stddef.h>
    #include <math.h>
    #include <string.h>

typedef struct {
    int taille;
    char signe;
    char zero;
    int *compt;
    int precision;
    int plus;
    int tmp;
    int truee;
    int retu;
    int hash;
} padding;

typedef struct Movement {
    float nx;
    float ny;
    float moveX;
    float moveY;
} movement;

typedef struct {
    float xstart;
    float ystart;
    float xend;
    float yend;
    float speed;
    float delay;
    float elapsedTime;
    int ishere;
    bool isProtected;
    sfSprite* sprite;
    sfRectangleShape *hitbox;
} plane;

typedef struct {
    int x;
    int y;
    float radius;
    sfSprite* sprite;
    sfCircleShape *circle;
} tour;

typedef struct tours {
    void *data;
    struct tours *next;
} tours;

typedef struct planes {
    void *data;
    struct planes *next;
} planes;

typedef struct {
    char *buff;
    char ***buffer;
    long int size;
    int fd;
} files;

typedef struct {
    files *file;
    sfVideoMode mode;
    sfRenderWindow* window;
    sfTexture* backgroundTexture;
    sfTexture* planeTexture;
    sfTexture* tourTexture;
    sfSprite* backgroundSprite;
    sfClock* totalElapsedTimeClock;
    plane ***grid;
    char time[10000];
    char planes[10000];
    int gridWidth;
    int gridHeight;
    bool hitboxVisible;
    bool spriteVisible;
    float centerX;
    float centerY;
    sfVector2f hitboxPos;
    sfVector2f hitboxSize;
    sfFont *font;
    sfText *text;
    sfText *textplanes;
    int end;
    bool angle;
} display;

int my_putchar(char c, padding p);
int my_put_nbr(long int nb, padding p);
void my_swap(int *a, int *b);
int my_putstr(char const *str, padding p);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void lim(void);
char *first_letter(char *str);
char *space(char *str);
int oct(unsigned int n, padding p);
int hexa_cap(unsigned int n, padding p);
int hexa(unsigned int n, padding p);
float my_put_float(double calcul, padding p);
int my_put_unbr(unsigned int nombre, padding p);
int point(long n, padding p);
int my_p_putchar(va_list list, padding p);
int my_p_put_nbr(va_list list, padding p);
int my_p_putstr(va_list list, padding p);
int my_p_hexa(va_list list, padding p);
int my_p_hexa_cap(va_list list, padding p);
int my_p_oct(va_list list, padding p);
int my_p_put_unbr(va_list list, padding p);
int my_p_point(va_list list, padding p);
int my_e(double n, padding p);
int my_cape(double n, padding p);
int my_p_putfloat(va_list list, padding p);
int my_p_e(va_list list, padding p);
int my_p_cape(va_list list, padding p);
int is_num(char c);
int my_p_hx(va_list list, padding p);
int my_p_hu(va_list list, padding p);
int my_p_hd(va_list list, padding p);
int my_p_lx(va_list list, padding p);
int my_p_lu(va_list list, padding p);
int my_p_ld(va_list list, padding p);
int my_p_lo(va_list list, padding p);
int my_p_lcapx(va_list list, padding p);
int my_p_ld(va_list list, padding p);
int my_p_ho(va_list list, padding p);
int my_p_hcapx(va_list list, padding p);
int my_ld(long int nb, padding p);
int my_lu(unsigned long int nb, padding p);
int my_lx(unsigned long int n, padding p);
int my_lo(unsigned long int n, padding p);
int my_lcapx(unsigned long int n, padding p);
int my_hd(short int nb, padding p);
int my_hu(unsigned short nb, padding p);
int my_hx(unsigned short int n, padding p);
int my_ho(unsigned short n, padding p);
int my_hcapx(unsigned short n, padding p);
int my_printf(const char *format, ...);
int call(const char *format, va_list ap, padding p);
int percent3(int *i, const char *format, va_list list, padding p);
int percent2(int *i, const char *format, va_list list, padding p);
int percent(int *i, const char *format, va_list list, padding p);
int call2(const char *format, va_list ap, int *i, padding p);
int my_point_precision(int *i, const char *format, va_list list,
    padding p);
int my_n(int *pointer, padding p);
int my_p_n(va_list list, padding p);
int my_flag(int *i, const char *format, padding p, int taille);
int my_len(int *i, const char *format, padding p, int taille);
int my_hhd(signed char nb, padding p);
int my_p_hhd(va_list list, padding p);
int my_hhu(unsigned char nb, padding p);
int my_p_hhu(va_list list, padding p);
int my_hhx(unsigned char n, padding p);
int my_p_hhx(va_list list, padding p);
int my_hho(unsigned char n, padding p);
int my_p_hho(va_list list, padding p);
int my_hhcapx(unsigned char n, padding p);
int my_p_hhcapx(va_list list, padding p);
int hexa_len(unsigned long int n, int i);
int point_len(long n, int i);
int oct_len(unsigned long int n, int i);
long point2_len(long n, int i);
int my_len_nbr(double nb);
int zeropad(int *i, const char *format, va_list list, padding p);
int pad(padding p);
int signe(int *i, const char *format, va_list list, padding p);
long negative(long a, padding p);
int my_putcharv2(char c, padding p);
int my_put_nbrpad(long int nb, padding p);
float my_put_floatpad(double calcul, padding p);
long int is_nega(double calcul, long int nombre, padding p);
long int last(int **tab_two, padding p, long int nombre);
long int number(int i, int **tab_two, long int nombre);
float my_put_float2(double calcul, int i, int **tab_two, padding p);
int blank(int *i, const char *format, va_list list, padding p);
int plus(int *i, const char *format, va_list list, padding p);
int padv2(padding p);
int my_p_put_nbr2(padding p);
int my_p_point2(padding p);
double my_p_putfloat2(padding p, double a);
int my_p_e2(padding p, double a);
double my_p_e3(padding p, double a);
long my_p_ld2(padding p);
int my_p_hd2(padding p);
int my_p_hhd2(padding p);
int percent4(int *i, const char *format, va_list list, padding p);
int my_p_lputfloat(va_list list, padding p);
int my_p_le(va_list list, padding p);
int my_p_lcape(va_list list, padding p);
int percent_stock(int *i, const char *format, va_list list, padding p);
int hashtag(int *i, const char *format, va_list list, padding p);
void inttostr(int number, char *str);
int file_buff_size(char const *file_path, files *file);
char **my_str_to_word_array(char const *str, char separator);
int my_lenarray(char **tab);
int my_get_number_only_number(char *str, int *taille);
void push_to_list_plane(planes **begin, plane *data);
void free_all(display *d, planes *p_list, tours *t_list);
void push_to_list_tour(tours **begin, tour *data);
void inttostr(int number, char *str);
void create_and_set_tour2(display *d, tour *t, tours **t_list);
void create_and_set_plane2(display *d, plane *p, planes **p_list);
int create_and_set_tour(display *d, char **line, tours **t_list);
int create_and_set_plane(display *d, char **line, planes **p_list);
int init_lists(display *d, planes **p_list, tours **t_list);
void init_buffer(display *d);
void initialize_display_settings(display *d);
int initialize_textures_and_grid(display *d);
int init_param(display *d);
void printfonc(void);
int validate_arguments(int ac);
int print_help_if_requested(int ac, char **av);
int initialize_display_and_lists(display *d, char *filename, planes **p,
    tours **t);
movement calculate_movement(plane *p, float deltaTime, display *d);
void update_position_and_status(plane *p, movement m, float deltaTime);
void flyplane(plane *p, float deltaTime, display *d);
void updategame(display *d, planes *p_list, float deltaTime);
float get_delta_time(sfClock *clock);
void isshow(display *d, plane *p);
void drawplane(display *d, planes *p_list, planes *p_node);
void drawtower(display *d, tours *t_list, tours *t_node);
void drawplanetower(display *d, planes *p_list, tours *t_list);
bool isneartower(display *d, plane *p, tours *t_list);
void update_protection_status(display *d, int x, int y, tours *t_list);
void detect_collision(display *d, int x, int y);
void checkcollision(display *d, int x, int y, tours *t_list);
void collisionsplane(display *d, tours *t_list);
int split_buffer_into_lines(display *d, char ***lines);
void process_lines_and_update_buffer(display *d, char **lines, int num_lines);
void reset_grid(display *d);
void update_grid_with_planes(display *d, planes *p_list);
void collisionsgrid(display *d, planes *p_list);
void window(display *d, planes *p, tours *t);
int tty(char **env, int display);

static const char *tab = "cdisxXoupfeEn";
static const char *tab2 = "ldlulxlolXhdhuhxhohX";
static const char *tab3 = "lldllullxllollXhhdhhuhhxhhohhX";

static const char *tab4 = "LdLuLxLoLXLfLeLE";
typedef int (*fonct_ptr)(va_list, padding);

static const fonct_ptr func[] = {my_p_putchar, my_p_put_nbr, my_p_put_nbr,
    my_p_putstr, my_p_hexa, my_p_hexa_cap, my_p_oct, my_p_put_unbr, my_p_point,
    my_p_putfloat, my_p_e, my_p_cape, my_p_n};
typedef int (*fonct_ptr2)(va_list, padding);

static const fonct_ptr2 func2[] = {my_p_ld, my_p_lu, my_p_lx, my_p_lo,
    my_p_lcapx, my_p_hd, my_p_hu, my_p_hx,
    my_p_ho, my_p_hcapx};
typedef int (*fonct_ptr3)(va_list, padding);

static const fonct_ptr3 func3[] = {my_p_ld, my_p_lu, my_p_lx, my_p_lo,
    my_p_lcapx, my_p_hhd, my_p_hhu, my_p_hhx,
    my_p_hho, my_p_hhcapx};
typedef int (*fonct_ptr4)(va_list, padding);

static const fonct_ptr4 func4[] = {my_p_ld, my_p_lu, my_p_lx, my_p_lo,
    my_p_lcapx, my_p_lputfloat, my_p_le, my_p_lcape};

#endif /* my_h */
