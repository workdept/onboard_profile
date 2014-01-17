/**
 * Reposition the jQuery UI datepicker dialog so it's closer to the input.
 *
 * For some reason, there's a bug where the default positioning is below
 * the input by about input.offsetHeight pixels.
 * 
 * This behaves weird in some cases, such as switching between fields without
 * setting the date, but in most "normal" cases, it properly adjusts the
 * position.
 */
(function( $, undefined ) {
  $(function() {
    var moved = false;

    // There's no onShow (or similar) event for the datepicker widget, so
    // hook into the focus event for the input.
    $('input.date-clear').focus(function(evt) {
      var $target = $(evt.target);
      var datepicker = $target.data('datepicker');
      var offsetTop;

      // The focus event will fire a couple of times, but only act when the
      // dialog is visible.
      if (datepicker && datepicker.dpDiv.is(':visible') && !moved) {
        offsetTop = datepicker.dpDiv.offset().top - (1.5 * evt.target.offsetHeight);
       
        datepicker.dpDiv.css('top', offsetTop + 'px');
        // Only adjust the position once.
        moved = true;
        $(evt.target).one('blur', function() {
          moved = false;
        });
      }
    });
  });
})(jQuery);
