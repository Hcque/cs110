#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "inode.h"
#include "diskimg.h"

#define INODE_SIZE 32  // size in bytes
#define INODE_PER_BLOCK (DISKIMG_SECTOR_SIZE/INODE_SIZE)
#define BLOCKS_PER_INDIR 256
#define NUM_INDIR_BLOCKS 7
#define TOTAL_BLOCKS_FROM_INDIR (BLOCKS_PER_INDIR * NUM_INDIR_BLOCKS)

int inode_iget(struct unixfilesystem *fs, int inumber, struct inode *inp) {
    char* start_inode = (char*)(&(fs->superblock)) + DISKIMG_SECTOR_SIZE * 1;
    if (start_inode == NULL) { fprintf(stderr, "Fail to probe start node."); }

    inp = (struct inode*)(start_inode + INODE_SIZE * (inumber - 1)); 
    if (inp == NULL) { return -1; }
    else { return 0; }
}

int inode_indexlookup(struct unixfilesystem *fs, struct inode *inp, int blockNum) {
   uint16_t *ap = (inp->i_addr);
   if (ap == NULL) return -1;
   int bNum = ap[blockNum];
   return bNum;
}

int inode_getsize(struct inode *inp) {
  return ((inp->i_size0 << 16) | inp->i_size1); 
}
