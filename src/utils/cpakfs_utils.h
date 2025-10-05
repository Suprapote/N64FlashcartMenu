#ifndef CPAKFS_UTILS__H__
#define CPAKFS_UTILS__H__

#include <stdbool.h>
#include <libdragon.h>
#include <stddef.h>

#define FS_BLOCK_DIVIDER (8 * 32)
#define MAX_NUM_NOTES 16

typedef struct {
    char gamecode[5];   // +1 for '\0'
    char pubcode[5];    // +1 for '\0'
    char filename[17];  // +1 for '\0'
    char ext[5];        // +1 for '\0'
} cpakfs_path_strings_t;

extern const char * const CPAK_MOUNT_ARRAY[4];

int get_block_size_from_fs_path(const char *filename_cpak);
void unmount_all_cpakfs();
int mount_cpakfs(int controller);
bool has_cpak(int controller);
int get_file_size_from_fs_path(const char *filename_cpak);
int extract_title_from_absolute_path(const char *path, char *outbuf, size_t outbuf_size);
int parse_cpakfs_fullname(const char *fullname, cpakfs_path_strings_t *out);
int file_exists_full(const char *full_mounted_path);
int inc_index_note(int current_index);
int dec_index_note(int current_index);
int pick_unique_fullname_with_mount(const char *mount_prefix,
                                    const char *desired_name,
                                    char *out_fullpath, size_t outsz,
                                    int (*exists_fullpath)(const char *fullpath));



#endif // CPAKFS_UTILS__H__
