int g_key_flag;

void g_key_1()
{
	g_key_flag = 1;
}

void g_key_0()
{
	g_key_flag = 0;
}
int is_g_key()
{
	return (g_key_flag);
}