/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:03:32 by chugon            #+#    #+#             */
/*   Updated: 2025/02/15 13:02:46 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

/** Defined boolean type 'true' and 'false'. */
typedef enum e_bool
{
	FT_FALSE = 0,
	FT_TRUE
}	t_bool;

/**
 * \defgroup linked Linked list manipulation
 * @{
 */

/**
 * The structure `struct s_list` represents a linked list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @}
 */

/**
 * \defgroup charmanip Character manipulation
 * @{
 */

/**
 * Checks if the given character is an alphabetic character (a-zA-Z).
 * 
 * \param c Character to classify.
 * \return Non-zero value if the character is an alphabetic character,
 * zero otherwise.
 */
int		ft_isalpha(int c);

/**
 * Checks if the given character is an alphanumeric character (0-9A-Za-z).
 * 
 * \param c Character to classify.
 * \return Non-zero value if the character is an alphanumeric character,
 * zero otherwise.
 */
int		ft_isalnum(int c);

/**
 * Checks if the given character is a numeric character (0-9).
 * 
 * \param c Character to classify.
 * \return Non-zero value if the character is a numeric character,
 * zero otherwise.
 */
int		ft_isdigit(int c);

/**
 * Checks if the given character is classified as printable.
 * 
 * \param c Character to classify.
 * \return Non-zero value if the character can be printed, zero otherwise.
 */
int		ft_isprint(int c);

/**
 * Checks if the given character is an ASCII character.
 * 
 * \param c Character to classify.
 * \return Non-zero value if the character is an ASCII character,
 * zero otherwise.
 */
int		ft_isascii(int c);

/**
 * Converts the given character to lowercase version.
 * The uppercase letters (A-Z) are replaced with respective (a-z).
 * \note The behavior is undefined if `c` is neither an `unsigned char` value
 * nor `EOF`.
 * 
 * \param c Character to be converted.
 * \return Lowercase version of `c` or unmodified `c` if no lowercase version.
 */
int		ft_tolower(int c);

/**
 * Converts the given character to uppercase version.
 * The lowercase letters (a-z) are replaced with respective (A-Z).
 * \note The behavior is undefined if `c` is neither an `unsigned char` value
 * nor `EOF`.
 *
 * \param c Character to be converted.
 * \return Uppercase version of `c` or unmodified `c` if no uppercase version.
 */
int		ft_toupper(int c);

/**
 * @}
 */

/**
 * \defgroup memmanip Memory manipulation
 * @{
 */

/**
 * Fills the first `count` bytes fo the memory area pointed to by `dst`
 * with the constant byte `c`. 
 *
 * \param dst Pointer to the object to fill.
 * \param c Fill byte.
 * \param count Number of bytes to fill.
 * \return Pointer to the memory area `dst`.
 */
void	*ft_memset(void *dst, int c, size_t count);

/**
 * Copies `count` bytes from memory area `src` to memory area `dst`.
 * \note The memory areas must not overlap.
 *
 * \param dst Pointer to the memory area to copy to.
 * \param src Pointer to the memory area to copy from.
 * \param count Number of bytes to copy.
 * \return Pointer to the memory area `dst`.
 */
void	*ft_memcpy(void *dst, const void *src, size_t count);

/**
 * Copies `count` bytes from memory area `src` to memory area `dst`.
 * The memory area may overlap.
 *
 * \param dest Pointer to the memory area to copy to.
 * \param src Pointer to the memory area to copy from.
 * \param count Number of bytes to copy.
 * \return Pointer to the memory area `dst`.
 */
void	*ft_memmove(void *dest, const void *src, size_t count);

/**
 * Finds the first occurrence of `c` in the initial `count` bytes of
 * the memory area pointed to by `ptr`.
 * \note Both `c` and the bytes of the memory area pointed to by `ptr`
 * are interpreted as `unsigned char`.
 *
 * \param ptr Pointer to the memory area to be examined.
 * \param c Byte to search for.
 * \param count Max number of bytes to examine.
 * \return Pointer to the matching byte or `NULL` if the character
 * does not occur in the given memory area.
 */
void	*ft_memchr(const void *ptr, int c, size_t count);

/**
 * Compares the first `count` bytes (each interpreted as `unsigned char`)
 * of the memory areas `lhs` and `rhs`.
 *
 * \param lhs, rhs Pointers to the objects to compare.
 * \param count Number of bytes to examine.
 * \return
 * - Zero if \a lhs and \a rhs compare equal, or if \a count is zero.
 * - Negative value if \a lhs appears before \a rhs in lexicographical order.
 * - Positive value if \a lhs appears after \a rhs in lexicographical order.
 */
int		ft_memcmp(const void *lhs, const void *rhs, size_t count);

/**
 * Sets the first `count` bytes of the memory area starting at the location
 * pointed to by `dst` to zero `'\0'`.
 *
 * \param dst Pointer to the memory area to set to zero.
 * \param count Number of bytes to set to zero.
 */
void	ft_bzero(void *dst, size_t count);

/**
 * Allocates memory for an array of `count` elements of `size` bytes each
 * and returns a pointer to the allocated memory.
 * The memory is set to zero.
 * \note If `count` or `size` is 0, this function returns a unique pointer
 * value that can later be successfully passed to `free()`.
 * \note If the `count * size` would result in interger overflow, then
 * an error is returned.
 *
 * \param count Number of elements.
 * \param size Size of each element.
 * \return Pointer to the allocated memory, or `NULL` if the allocation fails.
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * @}
 */

/**
 * \defgroup strexam String examination
 * @{
 */

/**
 * Calculates the length of the string pointed to by `str`, excluding
 * the terminating null byte `'\0'`.
 *
 * \param str Pointer to the null-terminated byte string to be examined.
 * \return The number of bytes in the string pointed to by `str`.
 */
size_t	ft_strlen(const char *str);

/**
 * Compares the first `count` bytes of the two strings `lhs` and `rhs`.
 * The comparison id done using `unsigned char`.
 * 
 * \param lhs, rhs Pointer to the null-terminated byte strings to compare.
 * \param count Maximum number of characters to compare.
 * \return
 * - Negative value if \a lhs appears before \a rhs in lexicographical order.
 * - Zero if \a lhs and \a rhs compare equal.
 * - Positive value if \a lhs appears after \a rhs in lexicographical order.
 */
int		ft_strncmp(const char *lhs, const char *rhs, size_t count);

/**
 * Locates the first occurrence of the null-terminated string `substr`
 * in the string `str`, where not more than `count` characters are searched.
 * \note Characters that appear after a `'\0'` are not searched.
 *
 * \param str Pointer to the null-terminated byte string to examine.
 * \param substr Pointer to the null-terminated byte string to search for.
 * \return Pointer to the first character of the found substring
 * in `str`, or a null pointer if such substring is not found.
 * If `substr` points to an empty string, `str` is returned.
 */
char	*ft_strnstr(const char *str, const char *substr, size_t count);

/**
 * @}
 */

/**
 * \defgroup strmanip String manipulation
 * @{
 */

/**
 * Returns a pointer to the first occurrence of the character `c` in
 * the string pointed to by `str`.
 * \note The terminating null byte is considered part of the string.
 *
 * \param str Pointer to the null-terminated byte string to be analyzed.
 * \param c Character to search for.
 * \return Pointer to the matched character or `NULL` if the character
 * is not found.
 */
char	*ft_strchr(const char *str, int c);

/**
 * Returns a pointer to the last occurrence of the character `c` in
 * the string pointed to by `str`.
 * \note The terminating null byte is considered part of the string.
 *
 * \param str Pointer to the null-terminated byte string to be analyzed.
 * \param c Character to search for.
 * \return Pointer to the matched character or `NULL` if the character
 * is not found.
 */
char	*ft_strrchr(const char *str, int c);

/**
 * Returns a pointer to a new string which is a duplicate of the string `str`.
 * \note Memory for the new string is obtained with `malloc(3)`, and
 * can be freed with `free(3)`.
 *
 * \param src Pointer to the null-terminated byte string to duplicate.
 * \return A pointer to the newly allocated string,
 * or a `NULL` if an error occured.
 */
char	*ft_strdup(const char *src);

/**
 * Copies up to `size - 1` characters form the null-terminated string
 * \a src to `dest`, null-terminating the result (as long as `size` is
 * larger than 0).
 * \note A byte for the null character `'\0'` should be included in `size`.
 * 
 * \param dst Pointer to the character array to write to.
 * \param src Pointer to the null-terminated byte string to copy from.
 * \param size The size of the destination buffer.
 * \return The total length of the string they tried to create, i.e. the length
 * of `src`.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * Appends the null-terminated string `src` to the end of `dst`.
 * It will append at most `size - strlen(dest) - 1` bytes, and
 * guarantee to null-terminate the result (as long as there is at least one
 * byte free in dest).
 * \note A byte for the null character `'\0'` should be included in `size`.
 *
 * \param dst Pointer to the null-terminated byte string to append to.
 * \param src Pointer to the character array to copy from.
 * \param size The size of the destination buffer.
 * \return The total length of the string it tried to create, which means
 * the initial length of `dst` plus the length of `src`.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @}
 */

/**
 * Interprets an integer value in a byte string pointed to by `str`.
 * 
 * Discards any whitespace characters until the first non-whitespace character
 * is found, then takes as many character as possible to form a valid integer
 * number representation and converts them to an integer value.
 * The valid integer consists of the following parts:
 * - plus or minus sign (optional)
 * - numeric digits
 * If the value of the result cannot be represented, i.e. the converted value
 * falls out of range of the corresponding type, the behavior is undefined.
 * 
 * \param str Pointer to the null-terminated byte string to be interpreted.
 * \return Integer value corresponding to the contents of `str` on success.
 * If no conversion can be performed, `0` is returned.
 */
int		ft_atoi(const char *str);

//*****************************************************************************/
//
// Part 2 - Additional functions
//
//*****************************************************************************/

/**
 * \addtogroup strmanip
 * @{
 */

/**
 * Allocates sufficient memory and returns a pointer to a null-terminated
 * substring from the string `str`.
 * The substring copies at most `len` characters from the string `str`,
 * starting at the position `start` and null-terminating the string.
 * \note If `start` is greater than the size of the string `str`, an empty
 * string is returned.
 * \note The returned pointer may subsequently be used as an argument to
 * the function `free(3)` to avoid a memory leak.
 *
 * \param str String from which to create a substring.
 * \param start Position of the first character to include.
 * \param len Maximum length of the substring.
 * \return Pointer to the newly allocated substring.
 * `NULL` is returned if the allocation fails.
 */
char	*ft_substr(const char *str, unsigned int start, size_t len);

/**
 * Allocates sufficient memory and returns a pointer to a null-terminated
 * string, which is the result of the concatenation of `prefix` and `suffix`.
 * \note The returned pointer may subsequently be used as an argument to
 * the function `free(3)` to avoid a memory leak.
 *
 * \param prefix Pointer to the null-terminated prefix string.
 * \param suffix Pointer to the null-terminated suffix string.
 * \return Pointer to the concatenated string, or `NULL` if the allocation
 * fails.
 */
char	*ft_strjoin(const char *prefix, const char *suffix);

/**
 * Allocates sufficient memory and returns a copy of the string `str` with
 * the characters specified in `set` removed from the beginning and the end
 * of the string.
 * \note The returned pointer may subsequently be used as an argument to
 * the function `free(3)` to avoid a memory leak.
 *
 * \param str Pointer to the null-terminated string to be trimmed.
 * \param set Reference set of characters to trim.
 * \return Pointer to the trimmed string, or `NULL` if the allocation fails.
 */
char	*ft_strtrim(const char *str, const char *set);

/**
 * Allocates and returns an array of strings obtained by splitting `str`, using
 * the character `c` as a delimiter.
 * \note The array is ended by a `NULL` pointer.
 * \note The returned array of pointers may subsequently be used as an argument
 * to the function `free(3)` to avoid a memory leak.
 *
 * \param str Pointer to the null-terminated string to be split.
 * \param c Delimiter character.
 * \return Address to the array of new strings resulting from the split.
 * `NULL` is returned if the allocation fails.
 */
char	**ft_split(const char *str, char c);

/**
 * Allocates sufficient memory and returns a pointer to the null-terminated
 * string representing the interger `nbr`.
 * \note The returned pointer may subsequently be used as an argument to
 * the function `free(3)` to avoid a memory leak.
 *
 * \param nbr Integer to convert.
 * \return Pointer to the null-terminated string representing the integer.
 * `NULL` is returned if the allocation fails.
 */
char	*ft_itoa(int nbr);

/**
 * Allocates sufficient memory and returns a pointer to a null-terminated string
 * resulting from successive application of the function `f` to each character
 * of string `str`.
 *
 * \param str Pointer to the null-terminated string on which to iterate.
 * \param f Function pointer to apply to each character.
 * \return Pointer to a null-terminated string created from the successive
 * applications of `f`, or `NULL` if the allocation fails.
 */
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));

/**
 * Applies the function `f` to each character of the string `str`.
 * The callback function has the position of the character as first argument.
 * Each character is passed by address to be modified if necessary.
 *
 * \param str Pointer to the null-terminated string on which to iterate.
 * \param f Function pointer to apply to each character.
 */
void	ft_striteri(char *str, void (*f)(unsigned int, char*));

/**
 * @}
 */

/**
 * \defgroup fdoutput File descriptor output
 * @{
 */

/**
 * Outputs the character `c` to the given file descriptor.
 *
 * \param c Character to output.
 * \param fd File descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * Outputs the null-terminated string `str` to the given file descriptor.
 *
 * \param str Pointer to the null-terminated string to output.
 * \param fd File descriptor on which to write.
 */
void	ft_putstr_fd(char *str, int fd);

/**
 * Outputs the null-terminated string `str` to the given file descriptor and
 * followed by the newline character `\n`.
 *
 * \param str Pointer to the null-terminated string to output.
 * \param fd File descriptor on which to write.
 */
void	ft_putendl_fd(char *str, int fd);

/**
 * Outputs the integer `nbr` to the given file descriptor.
 *
 * \param nbr Integer to output.
 * \param fd File descriptor on which to write.
 */
void	ft_putnbr_fd(int nbr, int fd);

/**
 * @}
 */

/**
 * \addtogroup linked
 * @{
 */

/**
 * Allocates and returns a new `struct s_list`.
 * The member field `content` is initialized with the value of the parameter,
 * and the member field `next` is initialized to `NULL`.
 * \note The returned pointer may subsequently be used as an argument to
 * the function `ft_lstdelone()` to avoid a memory leak.
 * 
 * \param content Data to initialize the member field of `struct s_list` with.
 * \return Pointer to the newly allocated structure or `NULL` if the allocation
 * fails.
 */
t_list	*ft_lstnew(void *content);

/**
 * Add the element specified by `element` at the beginning of the list.
 *
 * \param lst Address to the pointer to the first element of the list.
 * \param element Pointer to the element to be added.
 */
void	ft_lstadd_front(t_list **lst, t_list *element);

/**
 * Add the element specified by `element` at the end of the list.
 *
 * \param lst Address to the pointer to the first element of the list.
 * \param element Pointer to the element to be added.
 */
void	ft_lstadd_back(t_list **lst, t_list *element);

/**
 * Returns the number of elements in the list.
 *
 * \param lst Pointer to the first element of the list.
 * \return Size of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * Returns the last element of the list.
 *
 * \param lst Pointer to the first element of the list.
 * \return Pointer to the last element of the list or `NULL` if the list
 * is empty.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * Deallocates the memory allocation pointed to by `lst`.
 * The member field `content` is deallocated by the function pointer `del`.
 * \note The member field `next` is not deallocated.
 *
 * \param lst Pointer to the element to be deallocated.
 * \param del Function pointer used to deallocate the member field `content`.
 */
void	ft_lstdelone(t_list	*lst, void (*del)(void *));

/**
 * Deallocates the memory allocation of all elements of the list.
 * \note The pointer to the list is then set to `NULL`.
 *
 * \param lst Address to the pointer to the first element of the list.
 * \param del Function pointer used to deallocate the member field `content`
 * of each element of the list.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * Iterates the list and applies the function `f` to the content of each
 * element of the list.
 *
 * \param lst Pointer to the first element of the list.
 * \param f Function pointer to apply to each element of the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * Creates a new list which is the result of successive applications of
 * the function `f` to the content of each element of the list.
 * \note The function `del` is used to delete the content of an element
 * if needed.
 *
 * \param lst Pointer to the first element of the list.
 * \param f Function pointer used to iterate on the list.
 * \param del Function pointer used to delete the content of and element.
 * \return Pointer to the first element of the new list, or `NULL` if
 * the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @}
 */

#endif // LIBFT_H

/**
 * \file libft.h
 * \brief A set of re-coded of the \b libc functions, present the same
 * prototype and behaviors as the originals.
 * This library contains additional functions and structure for linked list.
 * \author Christian Hugon
 * \version 1.0
 */
