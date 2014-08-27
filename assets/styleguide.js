(function($, Drupal){
  Drupal.behaviors.styleguide = {
    attach: function (context, settings) {
      var $elements = $('input, button, textarea, select').not('[type="hidden"]').not($('.select2-container input'));
      var throbbers = [];
      var wrappers = [];

      $elements.each(function() {
        if ($(this).parents('.throbber-toggles').length > 0) {
          return;
        }
        var throbber = $('<div class="ajax-progress ajax-progress-throbber"><div class="throbber">&nbsp;</div></div>').get(0);
        var wrapper = $(this).parents('.form-item').first();
        throbbers.push(throbber);
        wrappers.push(wrapper);
        $(this).after(throbber);
      });

      if ($.fn.hasOwnProperty('hurricane')) {
        $(throbbers).find('.throbber').hurricane('start');
        $('.styleguide-throbbers-redraw', context).click(function(event){
          event.preventDefault();
          $(throbbers).find('.throbber').hurricane('redraw');
          $(throbbers).find('.throbber').hurricane('start');
        });
      }
      else {
        $('.styleguide-throbbers-redraw', context).remove();
      }

      $(throbbers).hide();

      $('.styleguide-throbbers', context).click(function(event){
        event.preventDefault();
        $(throbbers).toggle();
        $(wrappers).toggleClass('form-ajax-progress');
      });
    }
  };
}(jQuery, Drupal));