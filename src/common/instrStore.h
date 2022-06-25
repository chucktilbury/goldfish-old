#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

void initInstrStore();

void loadInstrStore(FILE* fp);
void saveInstrStore(FILE* fp);

unsigned long getInstrIndex();
unsigned long getInstrLen();
unsigned long getLabelAddr();
void setInstrIndex(unsigned long idx);
void incInstrIndex(int idx);
bool isInstrEnded();
void write_instr_obj(void* ptr, size_t size);
void write_instr_8(uint8_t v);
void write_instr_16(uint16_t v);
void read_instr_obj(void* ptr, size_t size);
void read_instr_8(uint8_t* v);
void read_instr_16(uint16_t* v);

#define WRITE_VM_OBJ(t, v) write_instr_obj(&(v), sizeof(t))
#define WRITE_VM_8(v) write_instr_8(v)
#define WRITE_VM_16(v) write_instr_16(v)

#define READ_VM_OBJ(t, v) read_instr_obj(&(v), sizeof(t))
#define READ_VM_8(v) read_instr_8(&(v))
#define READ_VM_16(v) read_instr_16(&(v))

#endif