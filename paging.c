/* page_init
 * Inputs: none 
 * Return Value: none
 * Function: sets the base addresses for the file director and page tables, sets the bits in memory based on the Intel documentation 
 * 
 */

void page_init() {
    int i;

    /* Initialize page tables for kernel memory and video memory */
    for (i = 0; i < 1024; i++) {
        page_table[i].kb.page_table_base_address = i;
        page_table[i].kb.present = 0; /* Default to not present */
        page_table[i].kb.read_write_permission = 1;
        page_table[i].kb.page_cache_disabled = 1; /* Disable caching for non-video memory */
    }

    /* Map video memory and terminals */
    page_table[0xb8].kb.page_table_base_address = (0xB8000 >> 12);
    page_table[0xb8].kb.present = 1;
    
    /* Map terminal pages */
    page_table[(TERM1 & 0x3ff000) >> 12].kb.page_table_base_address = (TERM1 >> 12);
    page_table[(TERM1 & 0x3ff000) >> 12].kb.present = 1;

    /* Set up page directory */
    page_directory[0].kb.page_table_base_address = ((int)page_table >> 12);
    page_directory[0].kb.present = 1;
    
    /* Load page directory and enable paging */
    loadPageDirectory(page_directory);
    enablePaging();
}
