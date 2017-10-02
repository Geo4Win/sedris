/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/30
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

/*
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 */

// $Id: seHelperImage.h,v 1.5 2006-05-03 15:21:11-04 shend Exp $

#ifndef _seHelperImage_h
#define _seHelperImage_h

/** @file seHelperImage.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seHelperImage.
*/

#include "seDRMImage.h"

#include "se_cpp_support.h"

namespace sedris {


/** @addtogroup utils
@{
*/

/** A helper for reading &lt;Image&gt; data.
seHelperImage takes care of memory management and rearrangement of image
data. Since the image data is managed by this class (users don't need to
free it), you can keep an instance of this class as long as you
need access to the image's data. This is true even if the transmittal
is closed or the image object used to initialize the helper goes out
of scope.

The following sample code demonstrates the use of this class to print
the red, green, and blue values of the first pixel of an image (the
image is known to be of signature SE_IMG_SIG_123COLOUR and with 8 bits
per component, first MIP level is used):
@code
    seDRMImage image;
    ... image object is retrieved

    seHelperImage hlpr;

    hlpr.init(image, 0); // 0 for first MIP level

    unsigned char *data_ptr = hlpr.getImageData();

    printf("%d, %d, %d", *data_ptr, *(data_ptr+1), *(data_ptr+2));
@endcode

You can also use this class to modify the image data. The following
code could be used as a follow up to the sample code above to perform
this:
@code
    ... image data obtained as above

    *data_ptr = 0; // R value of above image set to 0

    // image data stored back in the image object
    image.putImageData(0, hlpr.getImageDataSize(), hlpr.getImageData());
@endcode

The following sample code demonstrates the use of this class to access
the image data by rearranging the data to conform to a specific
organization:
@code
    seDRMImage image;
    ... image object is retrieved

    SE_Desired_Image_Parameters desired_param;
    seHelperImage hlpr;

    // ... fill out "desired_param" as needed, such as colour model,
    // scan direction, bits per component, etc.

    hlpr.init(image, mip_level, &desired_param);

    unsigned char *data_ptr = hlpr.getImageData();

    //... access the rearranged image data pointed by "data_ptr"
@endcode
Note that if you rearrange the image data, then in general you will not
be able to put the image data back without first rearranging it again to
match the original image format (unless, of course, you change the fields
of the image object containing the data to match the rearranged image
data parameters).

@note Image data organization is dependent on the image's signature,
    its scan direction, and the component bit sizes. The general storage
    mechanism for the texels is by putting all the components for each
    texel together, followed by all the components for the next texel,
    and so on. This is texel (pixel) data ordering. Scan line (all the
    red values on the first scan line, then all the green values ...)
    and image plane ordering (all the values of red within the image,
    then all the values of green...) are not supported.

@warning Be careful when using this class in STL containers, since
    some operations may require copy/reallocation of data which
    could adversely impact performance.

@author Warren Macchi
*/
class EXPORT_DLL seHelperImage
{
public:

    /// Constructor
    seHelperImage();

    /// Copy constructor.
    seHelperImage( const seHelperImage& other );

    /// Assignment
    seHelperImage& operator=( const seHelperImage& other );

    /// Destructor
    virtual ~seHelperImage();

    /** Initializes the helper and retrieves the image data.
        The @p mip_level must be &lt; image's level count (0-based).
        Optional @p des_params causes a rearranging of the image data.

        @note After calling this function, any previous data allocated by
            this class is freed (hence all previously returned pointers
            become invalid).
        @param image in: the &lt;Image&gt; object to retrieve data from
        @param mip_level in: the MIP level desired
        @param des_params in (optional): if provided, instructs the helper
            to rearrange the image data
    */
    void init( seDRMImage &image,
                SE_Short_Integer_Unsigned  mip_level,
                const SE_Desired_Image_Parameters *des_params = NULL );

    /** Returns the pointer to the image data.
        Since the image data is managed by this class (users don't need to
        free it), you can keep an instance of this class as long as you
        need access to the image's data. This is true even if the transmittal
        is closed or the image object used to initialize the helper goes out
        of scope.
        @warning Once this class instance goes out of scope, is deleted, or
            is initialized with a new Image object, the returned pointer
            becomes invalid.
    */
    SE_Byte_Unsigned *getImageData() { return _data; }

    /// Returns the number of bytes in the (possibly rearranged) image data.
    SE_Integer_Unsigned getImageDataSize() { return _data_size; }

    /** Returns the number of bytes in a rearranged image data.
        Normally you would not need to use this method. It is provided
        in case you want to know the size of an image that you are planning
        to rearrange (possibly to make a choice as to whether to proceed
        to use the helper or not).
        @param des_params in: the parameters for the rearranging
        @param size_horizontal in: the horizontal size of the image
        @param size_vertical in: the vertical size of the image
        @param size_z in: the z size of the image
    */
    static SE_Integer_Unsigned getRearrangedDataSize(
                                const SE_Desired_Image_Parameters *des_params,
                                SE_Integer_Unsigned size_horizontal,
                                SE_Integer_Unsigned size_vertical,
                                SE_Integer_Unsigned size_z );

protected:

    /// Resets the helper's data
    void reset();

    SE_Byte_Unsigned *_data; ///< The image data
    SE_Integer_Unsigned _data_size; ///< The size of image data
};


/** @} */

} // namespace sedris

#endif // _seHelperImage_h
