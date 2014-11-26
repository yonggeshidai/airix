#ifndef PMM_H
#define PMM_H

#include <kernel/base_types.h>

/* This file define Physical Memory Manager */

/* Memory map entry struct */
struct mmap_entry
{
    void *base;             /* Base address */
    void *base_high;        /* For 64 bits address */
    uint32_t length;        /* Region length */
    uint32_t length_high;   /* For 64 bits length */
    uint32_t type;          /* Region type */
    uint32_t acpi_attr;     /* ACPI 3.0 extended attributes bitfield */
};

/* Values of struct mmap_entry.type */
#define PMM_MM_ENTRY_TYPE_NORMAL 1
#define PMM_MM_ENTRY_TYPE_RESERVED 2
#define PMM_MM_ENTRY_TYPE_ACPI_REC 3
#define PMM_MM_ENTRY_TYPE_ACPI_NVS 4
#define PMM_MM_ENTRY_TYPE_BAD 5

/* PMM init function */
void init_pmm(struct mmap_entry *entries, uint32_t num);

#endif // PMM_H
