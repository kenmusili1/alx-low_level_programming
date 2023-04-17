#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure to store information about dogs
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Description: Structure to store information about dogs
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

#endif /* DOG_H */
