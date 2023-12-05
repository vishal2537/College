#include <stdio.h>
#include <stdlib.h>

typedef struct photo
{
    int photo_id;
    int ratings[10];
    int rating_count;
    int primordial_rating;
    float average_rating;
    int max_heap_rating[6];
    int max_heap_size;
    int min_heap_rating[6];
    int min_heap_size;
} photo;

void add_rating(photo photos[], int size, int indx);
void print_photo(photo photo);
int get_median(int min_heap[], int min_heap_size, int max_heap[], int max_heap_size);
void stabilize_median(int min_heap[], int *min_heap_size, int max_heap[], int *max_heap_size, int median, int rate);

void swap_photo(photo photos[], int first, int second)
{
    photo temp = photos[first];
    photos[first] = photos[second];
    photos[second] = temp;
}

void int_swap(int array[], int first, int second)
{
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

float average(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum / size;
}

int check_rating(int rating, int median)
{
    // if (rating >= 0 && rating >= median - 3 && rating <= 20 && rating <= median + 3)
    if (rating >= 0 && rating <= 20 && (rating <= median + 3 || rating >= median -3))

    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int find_identifier(photo photos[], int size, int photo_id)
{
    for (int i = 0; i < size; i++)
    {
        if (photos[i].photo_id == photo_id)
        {
            return i;
        }
    }
    return -1;
}

int find_min_identifier(photo photos[], int size)
{
    int min = photos[0].photo_id;
    int min_index = -1;
    for (int i = 0; i < size; i++)
    {
        if (photos[i].photo_id <= min)
        {
            min = photos[i].photo_id;
            min_index = i;
        }
    }
    return min_index;
}

int find_max_identifier(photo photos[], int size)
{
    int max = photos[0].photo_id;
    int max_index = -1;
    for (int i = 0; i < size; i++)
    {
        if (photos[i].photo_id >= max)
        {
            max = photos[i].photo_id;
            max_index = i;
        }
    }
    return max_index;
}

void photo_max_heapify_up(photo photos[], int size, int indx)
{
    if (indx)
    {
        int parent;
        if (indx % 2 == 0)
        {
            parent = (indx - 2) / 2;
        }
        else
        {
            parent = (indx - 1) / 2;
        }
        if (photos[parent].average_rating < photos[indx].average_rating)
        {
            swap_photo(photos, indx, parent);
            photo_max_heapify_up(photos, size, parent);
        }
    }
}

void photo_max_heapify_down(photo photos[], int size, int indx)
{
    int maximum = indx;
    int left = 2 * indx + 1;
    int right = 2 * indx + 2;

    if (left < size && photos[left].average_rating > photos[maximum].average_rating)
    {
        maximum = left;
    }
    if (right < size && photos[right].average_rating > photos[maximum].average_rating)
    {
        maximum = right;
    }
    if (maximum != indx)
    {
        swap_photo(photos, maximum, indx);
        photo_max_heapify_down(photos, size, maximum);
    }
}

void photo_build_max_heap(photo photos[], int size)
{
    int init = (size / 2) - 1;

    for (int i = init; i >= 0; i--)
    {
        photo_max_heapify_down(photos, size, i);
    }
}

photo new_photo(photo photos[], int size)
{
    photo new;
    int max_idx = find_max_identifier(photos, size);
    if (max_idx == -1)
    {
        new.photo_id = 1;
    }
    else
    {
        new.photo_id = photos[max_idx].photo_id + 1;
    }
    new.rating_count = 0;
    new.average_rating = 0;
    new.min_heap_size = 0;
    new.max_heap_size = 0;
    return new;
}

void add_photo(photo photos[], int *size)
{
    if (*size == 1)
    {
        photos[*size] = new_photo(photos, *size);
        printf("Jury:\n");
        add_rating(photos, *size, *size);
        add_rating(photos, *size, *size);
        add_rating(photos, *size, *size);
        (*size)++;
        photo_build_max_heap(photos, *size);
    }
    else if (*size < 10)
    {
        photos[*size] = new_photo(photos, *size);
        printf("Jury:\n");
        add_rating(photos, *size, *size);
        add_rating(photos, *size, *size);
        add_rating(photos, *size, *size);
        (*size)++;
        photo_max_heapify_up(photos, *size, (*size) - 1);
    }
    else
    {
        int old = find_min_identifier(photos, *size);
        photos[old] = new_photo(photos, *size);
        printf("Jury:\n");
        add_rating(photos, *size, old);
        add_rating(photos, *size, old);
        add_rating(photos, *size, old);
        photo_max_heapify_up(photos, *size, old);
    }
}
void delete_photo(photo photos[], int *size)
{
    if (*size == 0)
    {
        printf("No photos in storage\n");
    }
    else
    {
        int photo_id;
        printf("Enter photo id of phototo be deleted(-1 to go back) : \n");
        scanf("%d", &photo_id);
        if (photo_id != -1)
        {
            int indx = find_identifier(photos, *size, photo_id);
            if (indx == -1)
            {
                printf("photo id not found\n");
            }
            else
            {
                printf("Photo being deleted:\n");
                print_photo(photos[indx]);
                if (indx != (*size) - 1)
                {
                    swap_photo(photos, indx, (*size) - 1);
                }
                (*size)--;
                photo_max_heapify_down(photos, *size, 0);
            }
        }
    }
}

void add_rating(photo photos[], int size, int indx)
{
    if (indx == -1)
    {
        printf("photo id not found\n");
    }
    else
    {
        int rating;
        printf("Enter rating:\n");
        scanf("%d", &rating);
        int median = get_median(photos[indx].min_heap_rating, photos[indx].min_heap_size, photos[indx].max_heap_rating, photos[indx].max_heap_size);
        if (check_rating(rating, median) || photos[indx].rating_count == 0)
        {
            if (photos[indx].rating_count < 10)
            {
                photos[indx].ratings[photos[indx].rating_count++] = rating;
            }
            else
            {
                photos[indx].ratings[photos[indx].primordial_rating] = rating;
                photos[indx].primordial_rating = (photos[indx].primordial_rating + 1) % photos[indx].rating_count;
            }
            photos[indx].average_rating = average(photos[indx].ratings, photos[indx].rating_count);
            stabilize_median(photos[indx].min_heap_rating, &(photos[indx].min_heap_size), photos[indx].max_heap_rating, &(photos[indx].max_heap_size), median, rating);
        }
        else
        {
            printf("invalid rating !!\nenter rating in range 0 to 20 .\n");

        }
    }
}

void rating_min_heapify_up(int array[], int size, int indx)
{
    if (indx)
    {
        int parent;
        if (indx % 2 == 0)
        {
            parent = (indx - 2) / 2;
        }
        else
        {
            parent = (indx - 1) / 2;
        }
        if (array[parent] > array[indx])
        {
            int_swap(array, indx, parent);
            rating_min_heapify_up(array, size, parent);
        }
    }
}

void rating_min_heapify_down(int array[], int size, int indx)
{

    int minimum = indx;
    int left = 2 * indx + 1;
    int right = 2 * indx + 2;

    if (left < size && array[left] < array[minimum])
    {
        minimum = left;
    }
    if (right < size && array[right] < array[minimum])
    {
        minimum = right;
    }
    if (minimum != indx)
    {
        int_swap(array, minimum, indx);
        rating_min_heapify_down(array, size, indx);
    }
}

void insert_min_heap(int min_heap[], int *min_heap_size, int key)
{
    min_heap[(*min_heap_size)++] = key;
    rating_min_heapify_up(min_heap, *min_heap_size, (*min_heap_size) - 1);
}

int get_min(int min_heap[])
{
    return min_heap[0];
}

int extract_min(int min_heap[], int *min_heap_size)
{
    if (*min_heap_size == 0)
    {
        return -1;
    }
    if (*min_heap_size == 1)
    {
        return min_heap[0];
    }
    int min = min_heap[0];
    min_heap[0] = min_heap[(*min_heap_size) - 1];
    rating_min_heapify_up(min_heap, (*min_heap_size) - 1, 0);
    return min;
}

void rating_max_heapify_up(int array[], int size, int indx)
{
    if (indx)
    {
        int parent;
        if (indx % 2 == 0)
        {
            parent = (indx - 2) / 2;
        }
        else
        {
            parent = (indx - 1) / 2;
        }
        if (array[parent] < array[indx])
        {
            int_swap(array, indx, parent);
            rating_max_heapify_up(array, size, parent);
        }
    }
}

void rating_max_heapify_down(int array[], int size, int indx)
{
    int maximum = indx;
    int left = 2 * indx + 1;
    int right = 2 * indx + 2;

    if (left < size && array[left] > array[maximum])
    {
        maximum = left;
    }
    if (right < size && array[right] > array[maximum])
    {
        maximum = right;
    }
    if (maximum != indx)
    {
        int_swap(array, maximum, indx);
        rating_max_heapify_down(array, size, indx);
    }
}

void insert_max_heap(int max_heap[], int *max_heap_size, int key)
{
    max_heap[(*max_heap_size)++] = key;
    rating_max_heapify_up(max_heap, *max_heap_size, (*max_heap_size) - 1);
}

int get_max(int max_heap[])
{
    return max_heap[0];
}

int extract_max(int max_heap[], int *max_heap_size)
{

    if (*max_heap_size == 0)
    {
        return -1;
    }
    if (*max_heap_size == 1)
    {
        return max_heap[0];
    }
    int max = max_heap[0];
    max_heap[0] = max_heap[(*max_heap_size) - 1];
    rating_max_heapify_down(max_heap, (*max_heap_size) - 1, 0);
    return max;
}

//          median
int get_median(int min_heap[], int min_heap_size, int max_heap[], int max_heap_size)
{
    if (max_heap_size == min_heap_size)
    {
        return (get_min(min_heap) + get_max(max_heap)) / 2;
    }
    else if (max_heap_size > min_heap_size)
    {
        return get_max(max_heap);
    }
    else if (max_heap_size < min_heap_size)
    {
        return get_min(min_heap);
    }
}

void stabilize_median(int min_heap[], int *min_heap_size, int max_heap[], int *max_heap_size, int median, int rate)
{
    if (*max_heap_size > *min_heap_size)
    {
        if (rate < median)
        {
            insert_min_heap(min_heap, min_heap_size, extract_max(max_heap, max_heap_size));
            insert_max_heap(max_heap, max_heap_size, rate);
        }
        else
        {
            insert_min_heap(min_heap, min_heap_size, rate);
        }
    }
    else if (*min_heap_size > *max_heap_size)
    {
        if (rate < median)
        {
            insert_max_heap(max_heap, max_heap_size, rate);
        }
        else
        {
            insert_max_heap(max_heap, max_heap_size, extract_min(min_heap, min_heap_size));
            insert_min_heap(min_heap, min_heap_size, rate);
        }
    }
    else
    {
        if (rate < median)
        {
            insert_max_heap(max_heap, max_heap_size, rate);
        }
        else
        {
            insert_min_heap(min_heap, min_heap_size, rate);
        }
    }
}

//                  Display
void print_photo(photo photo)
{
    int median = get_median(photo.min_heap_rating, photo.min_heap_size, photo.max_heap_rating, photo.max_heap_size);
    printf(" PHOTO_ID: %d,\t AVERAGE_RATING: %d,\t MEDIAN_RATING: %d,\t Ratings: { ", photo.photo_id, (int)photo.average_rating, median);
    for (int i= 0; i< photo.rating_count; i++)
    {
        printf("%d ", photo.ratings[i]);
    }
    printf("}\n");
}
void print_all_photos(photo photos[], int size)
{
    printf("Current Size : %d \n", size);
    for (int i = 0; i < size; i++)
    {
        print_photo(photos[i]);
    }
}

int main()
{
    photo photosdsliiitg[10];
    int photo_count = 0;
    while (1)
    {
        printf("1.NEW_SUBMISSION\n2.ADD_NEW_RATING\n3.DELETE_PHOTO_ID\n4.PRINT_ALL_PHOTO_ID\n5.PRINT_HIGHEST_PHOTO_ID\n6.EXIT\n");
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            add_photo(photosdsliiitg, &photo_count);
        }
        else if (ch == 2)
        {
            int photo_id;
            printf("Enter photo id of photo to rate\n");
            scanf("%d", &photo_id);
            int indx = find_identifier(photosdsliiitg, photo_count, photo_id);
            print_photo(photosdsliiitg[indx]);
            add_rating(photosdsliiitg, photo_count, find_identifier(photosdsliiitg, photo_count, photo_id));
        }
        else if (ch == 3)
        {
            delete_photo(photosdsliiitg, &photo_count);
        }
        else if (ch == 4)
        {
            print_all_photos(photosdsliiitg, photo_count);
        }
        else if (ch == 5)
        {
            if (photo_count != 0)
            {
                print_photo(photosdsliiitg[0]);
            }
        }
        else if (ch == 6)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Choice\n");
        }
    }
}
